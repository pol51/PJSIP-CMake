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
  set(PJMEDIA_SRC ${PJMEDIA_SRC}
    ../src/pjmedia/transport_srtp.c)
  include_directories(AFTER SYSTEM ../../third_party/srtp/include ../../third_party/srtp/crypto/include ../../third_party/build/srtp)
endif()

if(WITH_AUDIODEV_PORTAUDIO)
  set(PJMEDIA-AUDIODEV_SRC ${PJMEDIA-AUDIODEV_SRC}
    ../src/pjmedia-audiodev/pa_dev.c)
endif()

if(WITH_CODEC_GSM)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/gsm.c)
endif()

if(WITH_CODEC_SPEEX)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/speex_codec.c)
endif()

if(WITH_CODEC_ILBC)
  set(PJMEDIA-CODECS_SRC ${PJMEDIA-CODECS_SRC}
    ../src/pjmedia-codec/ilbc.c)
endif()

add_library(pjmedia OBJECT ${PJMEDIA_SRC} ${PJMEDIA_INC} ${PJMEDIA-AUDIODEV_SRC} ${PJMEDIA-CODECS_SRC})
