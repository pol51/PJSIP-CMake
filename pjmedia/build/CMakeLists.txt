set(PJMEDIA_SRC
  ../src/pjmedia/alaw_ulaw.c
  ../src/pjmedia/alaw_ulaw_table.c
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
  ../src/pjmedia/tonegen.c
  ../src/pjmedia/transport_adapter_sample.c
  ../src/pjmedia/transport_ice.c
  ../src/pjmedia/transport_loop.c
  ../src/pjmedia/transport_srtp.c
  ../src/pjmedia/transport_udp.c
  ../src/pjmedia/wav_player.c
  ../src/pjmedia/wav_playlist.c
  ../src/pjmedia/wav_writer.c
  ../src/pjmedia/wave.c
  ../src/pjmedia/wsola.c
)

file(GLOB_RECURSE PJMEDIA_INC ../include/*.h)
include_directories(AFTER SYSTEM ../../third_party/srtp/include ../../third_party/srtp/crypto/include ../../third_party/build/srtp)

add_library(pjmedia OBJECT ${PJMEDIA_SRC} ${PJMEDIA_INC})
