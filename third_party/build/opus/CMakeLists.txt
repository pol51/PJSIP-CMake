file(GLOB OPUS_SRC ../../opus/src/*.c)
list(REMOVE_ITEM OPUS_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../opus/src/opus_demo.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../opus/src/mlp_train.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../opus/src/opus_compare.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../opus/src/repacketizer_demo.c)
file(GLOB_RECURSE OPUS_HEADERS ../../opus/include/*.h ../../opus/src/*.h ../../opus/celt/*.h ../../opus/silk/*.h)
set(OPUS_SRC ${OPUS_SRC} ${OPUS_HEADERS}
    ../../opus/celt/celt_decoder.c
    ../../opus/celt/celt_encoder.c
    ../../opus/celt/entenc.c
    ../../opus/celt/entdec.c
    ../../opus/celt/modes.c
    ../../opus/celt/celt.c
    ../../opus/celt/bands.c
    ../../opus/celt/mdct.c
    ../../opus/celt/pitch.c
    ../../opus/celt/vq.c
    ../../opus/celt/celt_lpc.c
    ../../opus/celt/quant_bands.c
    ../../opus/celt/entcode.c
    ../../opus/celt/rate.c
    ../../opus/celt/mathops.c
    ../../opus/celt/kiss_fft.c
    ../../opus/celt/cwrs.c
    ../../opus/celt/laplace.c
    ../../opus/silk/init_encoder.c
    ../../opus/silk/init_decoder.c
    ../../opus/silk/check_control_input.c
    ../../opus/silk/control_codec.c
    ../../opus/silk/resampler.c
    ../../opus/silk/tables_other.c
    ../../opus/silk/stereo_encode_pred.c
    ../../opus/silk/stereo_decode_pred.c
    ../../opus/silk/encode_indices.c
    ../../opus/silk/decode_indices.c
    ../../opus/silk/encode_pulses.c
    ../../opus/silk/decode_pulses.c
    ../../opus/silk/HP_variable_cutoff.c
    ../../opus/silk/LP_variable_cutoff.c
    ../../opus/silk/stereo_LR_to_MS.c
    ../../opus/silk/stereo_MS_to_LR.c
    ../../opus/silk/control_SNR.c
    ../../opus/silk/decoder_set_fs.c
    ../../opus/silk/decode_frame.c
    ../../opus/silk/gain_quant.c
    ../../opus/silk/A2NLSF.c
    ../../opus/silk/NLSF2A.c
    ../../opus/silk/process_NLSFs.c
    ../../opus/silk/NSQ.c
    ../../opus/silk/NSQ_del_dec.c
    ../../opus/silk/VAD.c
    ../../opus/silk/CNG.c
    ../../opus/silk/PLC.c
    ../../opus/silk/NLSF_unpack.c
    ../../opus/silk/control_codec.c
    ../../opus/silk/control_audio_bandwidth.c
    ../../opus/silk/tables_pitch_lag.c
    ../../opus/silk/tables_NLSF_CB_NB_MB.c
    ../../opus/silk/tables_NLSF_CB_WB.c
    ../../opus/silk/tables_gain.c
    ../../opus/silk/resampler_rom.c
    ../../opus/silk/resampler_private_up2_HQ.c
    ../../opus/silk/resampler_private_IIR_FIR.c
    ../../opus/silk/resampler_private_down_FIR.c
    ../../opus/silk/quant_LTP_gains.c
    ../../opus/silk/tables_LTP.c
    ../../opus/silk/tables_pulses_per_block.c
    ../../opus/silk/shell_coder.c
    ../../opus/silk/code_signs.c
    ../../opus/silk/biquad_alt.c
    ../../opus/silk/stereo_find_predictor.c
    ../../opus/silk/stereo_quant_pred.c
    ../../opus/silk/decode_parameters.c
    ../../opus/silk/decode_core.c
    ../../opus/silk/table_LSF_cos.c
    ../../opus/silk/bwexpander_32.c
    ../../opus/silk/bwexpander.c
    ../../opus/silk/resampler_private_AR2.c
    ../../opus/silk/VQ_WMat_EC.c
    ../../opus/silk/inner_prod_aligned.c
    ../../opus/silk/NLSF_decode.c
    ../../opus/silk/decode_pitch.c
    ../../opus/silk/LPC_inv_pred_gain.c
    ../../opus/silk/NLSF_VQ_weights_laroia.c
    ../../opus/silk/NLSF_VQ.c
    ../../opus/silk/NLSF_del_dec_quant.c
    ../../opus/silk/resampler_down2.c
    ../../opus/silk/resampler_down2_3.c
    ../../opus/silk/sort.c
    ../../opus/silk/NLSF_encode.c
    ../../opus/silk/NLSF_stabilize.c
    ../../opus/silk/pitch_est_tables.c
    ../../opus/silk/LPC_analysis_filter.c
    ../../opus/silk/ana_filt_bank_1.c
    ../../opus/silk/sigm_Q15.c
    ../../opus/silk/sum_sqr_shift.c
    ../../opus/silk/interpolate.c
    ../../opus/silk/enc_API.c
    ../../opus/silk/dec_API.c
    ../../opus/silk/lin2log.c
    ../../opus/silk/log2lin.c)

if(WITH_FLOATING_POINT)
    include_directories(AFTER SYSTEM  ../../opus/silk/float)
    file(GLOB_RECURSE OPUS_FLOAT_SRC ../../opus/silk/float/*.c ../../opus/silk/float/*.h)
    set(OPUS_SRC ${OPUS_SRC} ${OPUS_FLOAT_SRC})
else()
    include_directories(AFTER SYSTEM  ../../opus/silk/fixed)
    file(GLOB_RECURSE OPUS_FIXED_SRC ../../opus/silk/fixed/*.c ../../opus/silk/fixed/*.h)
    set(OPUS_SRC ${OPUS_SRC} ${OPUS_FIXED_SRC})
    add_definitions(-DFIXED_POINT=1)
endif()

add_definitions(-DOPUS_BUILD=1 -DUSE_ALLOCA=1)

include_directories(AFTER SYSTEM  . ../../opus/ ../../opus/include/ ../../opus/celt/ ../../opus/silk/)

add_library(opus OBJECT ${OPUS_SRC})
