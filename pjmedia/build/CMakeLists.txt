set(PJMEDIA_SRC
  ../src/pjmedia/alaw_ulaw.c
  ../src/pjmedia/alaw_ulaw_table.c
  ../src/pjmedia/audiodev.c
  ../src/pjmedia/bidirectional.c
  ../src/pjmedia/clock_thread.c
  ../src/pjmedia/codec.c
  ../src/pjmedia/conference.c
  ../src/pjmedia/conf_switch.c
  ../src/pjmedia/delaybuf.c
  ../src/pjmedia/echo_common.c
  ../src/pjmedia/echo_port.c
  ../src/pjmedia/echo_speex.c
  ../src/pjmedia/echo_suppress.c
  ../src/pjmedia/endpoint.c
  ../src/pjmedia/errno.c
  ../src/pjmedia/format.c
  ../src/pjmedia/g711.c
  ../src/pjmedia/jbuf.c
  ../src/pjmedia/master_port.c
  ../src/pjmedia/mem_capture.c
  ../src/pjmedia/mem_player.c
  ../src/pjmedia/null_port.c
  ../src/pjmedia/plc_common.c
  ../src/pjmedia/port.c
  ../src/pjmedia/splitcomb.c
  ../src/pjmedia/resample_resample.c
  ../src/pjmedia/resample_libsamplerate.c
  ../src/pjmedia/resample_port.c
  ../src/pjmedia/rtcp.c
  ../src/pjmedia/rtcp_xr.c
  ../src/pjmedia/rtp.c
  ../src/pjmedia/sdp.c
  ../src/pjmedia/sdp_cmp.c
  ../src/pjmedia/sdp_neg.c
  ../src/pjmedia/session.c
  ../src/pjmedia/silencedet.c
  ../src/pjmedia/sound_legacy.c
  ../src/pjmedia/sound_port.c
  ../src/pjmedia/stereo_port.c
  ../src/pjmedia/stream.c
  ../src/pjmedia/stream_info.c
  ../src/pjmedia/stream_common.c
  ../src/pjmedia/tonegen.c
  ../src/pjmedia/transport_adapter_sample.c
  ../src/pjmedia/transport_ice.c
  ../src/pjmedia/transport_loop.c
  ../src/pjmedia/transport_udp.c
  ../src/pjmedia/types.c
  ../src/pjmedia/wav_player.c
  ../src/pjmedia/wav_playlist.c
  ../src/pjmedia/wav_writer.c
  ../src/pjmedia/wave.c
  ../src/pjmedia/wsola.c
)

set(PJMEDIA-AUDIODEV_SRC
  ../src/pjmedia-audiodev/audiodev.c
  ../src/pjmedia-audiodev/errno.c
  ../src/pjmedia-audiodev/legacy_dev.c
  ../src/pjmedia-audiodev/null_dev.c)

set(PJMEDIA-CODECS_SRC
  ../src/pjmedia-codec/audio_codecs.c)

file(GLOB_RECURSE PJMEDIA_INC ../include/*.h)

if(WITH_SRTP)
  if(WITH_BUILTIN_OPENSSL)
    include_directories(BEFORE SYSTEM
      ../../third_party
      ../../third_party/openssl
    ${CMAKE_CURRENT_BINARY_DIR}/../../third_party/build/openssl
    ${CMAKE_CURRENT_BINARY_DIR}/../../third_party/build/openssl/openssl/crypto)
  endif()

  set(PJMEDIA_SRC ${PJMEDIA_SRC}
    ../src/pjmedia/transport_srtp.c)
  include_directories(AFTER SYSTEM ../../third_party/srtp/include ../../third_party/srtp/crypto/include ../../third_party/build/srtp)
endif()

if(WITH_AUDIODEV_PORTAUDIO)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/pa_dev.c)
  include_directories(../../third_party/portaudio/include)
endif()

if(WITH_AUDIODEV_COREAUDIO)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/coreaudio_dev.m)
endif()

if(WITH_AUDIODEV_OPENSL)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/opensl_dev.c)
endif()

if(WITH_AUDIODEV_ALSA)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/alsa_dev.c)
endif()

if(WITH_AUDIODEV_WMME)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/wmme_dev.c)
  include_directories(../../third_party/portaudio/include)
endif()

if(WITH_PASSTHROUGH_CODECS)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/passthrough.c)
endif()

if(WITH_CODEC_GSM)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/gsm.c)
endif()

if(WITH_CODEC_OPUS)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/opus.c)
  include_directories(AFTER SYSTEM ../../third_party/opus/include)
endif()

if(WITH_CODEC_SPEEX)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/speex_codec.c)
  include_directories(AFTER SYSTEM ../../third_party/speex/include)
endif()

if(WITH_CODEC_ILBC)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/ilbc.c)
endif()

if(WITH_CODEC_IPP)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/ipp_codecs.c)
endif()

if(WITH_CODEC_L16)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/l16.c)
endif()

if(WITH_CODEC_G722)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/g722.c
    ../src/pjmedia-codec/g722/g722_dec.c
    ../src/pjmedia-codec/g722/g722_enc.c)
endif()

if(WITH_CODEC_G7221)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/g7221.c
    ../src/pjmedia-codec/g7221_sdp_match.c)
  include_directories(AFTER SYSTEM ../../third_party/)
endif()

if(WITH_CODEC_AMRWB OR WITH_CODEC_AMRNB)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/opencore_amr.c
    ../src/pjmedia-codec/amr_sdp_match.c)
endif()

add_library(pjmedia OBJECT ${PJMEDIA_SRC} ${PJMEDIA_INC} ${PJMEDIA-AUDIODEV_SRC} ${PJMEDIA-CODECS_SRC})
