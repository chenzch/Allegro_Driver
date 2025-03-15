//---------------------------------------------------------------------------------------------------------------------
//
// WTMEC CORPORATION CONFIDENTIAL
// ________________________________
//
// [2025] Wtmec Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Wtmec Corporation owns all rights to this work and intends to maintain it in confidence to
// preserve its trade secret status. Wtmec Corporation reserves the right, under the copyright
// laws of the United States or those of any other country that may have jurisdiction, to protect
// this work as an unpublished work, in the event of an inadvertent or deliberate unauthorized
// publication. Wtmec Corporation also reserves its rights under all copyright laws to protect
// this work as a published work, when appropriate. Those having access to this work may not copy
// it, use it, modify it, or disclose the information contained in it without the written
// authorization of Wtmec Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#if !defined(A81415_H)
#define A81415_H (1)

#if defined(__cplusplus)
extern "C" {
#endif

#define A81415_CMD_READ  (0)
#define A81415_CMD_WRITE (1)

#define A81415_REG_STATUS0        (0)
#define A81415_REG_STATUS1        (1)
#define A81415_REG_STATUS2        (2)
#define A81415_REG_STATUS3        (3)
#define A81415_REG_DIAGNOSTIC0    (4)
#define A81415_REG_DIAGNOSTIC1    (5)
#define A81415_REG_DIAGNOSTIC2    (6)
#define A81415_REG_KEYS           (7)
#define A81415_REG_CONFIG0        (8)
#define A81415_REG_CONFIG1        (9)
#define A81415_REG_CONFIG2        (10)
#define A81415_REG_CONFIG3        (11)
#define A81415_REG_CONFIG4        (12)
#define A81415_REG_CONFIG5        (13)
#define A81415_REG_CONFIG6        (14)
#define A81415_REG_READBACK       (15)
#define A81415_REG_VERIFY_RESULT0 (16)
#define A81415_REG_VERIFY_RESULT1 (17)
#define A81415_REG_WSI_CONFIG     (18)
#define A81415_REG_WSI_FAULT      (19)
#define A81415_REG_WSI_DATA1      (20)
#define A81415_REG_WSI_DATA2      (21)

#define A81415_RES_ADDRESS_OFFSET   (26)
#define A81415_RES_ADDRESS_WIDTH    (5)
#define A81415_RES_ADDRESS_MASK     (0x1F)
#define A81415_RES_ADDRESS(X)       (((X) >> A81415_RES_ADDRESS_OFFSET) & A81415_RES_ADDRESS_MASK)
#define A81415_RES_FRAMECNT_OFFSET  (23)
#define A81415_RES_FRAMECNT_WIDTH   (3)
#define A81415_RES_FRAMECNT_MASK    (0x7)
#define A81415_RES_FRAMECOUNT(X)    (((X) >> A81415_RES_FRAMECNT_OFFSET) & A81415_RES_FRAMECNT_MASK)
#define A81415_RES_FAULTFLAG_OFFSET (22)
#define A81415_RES_FAULTFLAG_WIDTH  (1)
#define A81415_RES_FAULTFLAG_MASK   (0x1)
#define A81415_RES_FAULTFLAG(X)     (((X) >> A81415_RES_FAULTFLAG_OFFSET) & A81415_RES_FAULTFLAG_MASK)
#define A81415_RES_DATA_OFFSET      (6)
#define A81415_RES_DATA_WIDTH       (16)
#define A81415_RES_DATA_MASK        (0xFFFF)
#define A81415_RES_DATA(X)          (((X) >> A81415_RES_DATA_OFFSET) & A81415_RES_DATA_MASK)
#define A81415_RES_DATAOK_OFFSET    (5)
#define A81415_RES_DATAOK_WIDTH     (1)
#define A81415_RES_DATAOK_MASK      (0x1)
#define A81415_RES_DATAOK(X)        (((X) >> A81415_RES_DATAOK_OFFSET) & A81415_RES_DATAOK_MASK)
#define A81415_RES_CRC_OFFSET       (0)
#define A81415_RES_CRC_WIDTH        (5)
#define A81415_RES_CRC_MASK         (0x1F)
#define A81415_RES_CRC(X)           (((X) >> A81415_RES_CRC_OFFSET) & A81415_RES_CRC_MASK)

/**
 * A81415 Status Register 0
 */
#define REG_STATUS0_VMON_F_MASK      (1 << 15)
#define REG_STATUS0_SE_S_MASK        (1 << 14)
#define REG_STATUS0_WD_F_S_MASK      (1 << 13)
#define REG_STATUS0_POE_S_MASK       (1 << 12)
#define REG_STATUS0_RESETN_S_MASK    (1 << 11)
#define REG_STATUS0_TSD_F_S_MASK     (1 << 10)
#define REG_STATUS0_EEPROM_F_MASK    (1 << 9)
#define REG_STATUS0_VUCSEL_F_MASK    (1 << 8)
#define REG_STATUS0_POE2_ERR_MASK    (1 << 7)
#define REG_STATUS0_POE1_ERR_MASK    (1 << 6)
#define REG_STATUS0_RESETN_ERR_MASK  (1 << 5)
#define REG_STATUS0_TSD_WARN_MASK    (1 << 4)
#define REG_STATUS0_ENCAN_S_MASK     (1 << 3)
#define REG_STATUS0_ENBAT_S_MASK     (1 << 2)
#define REG_STATUS0_ENCAN_LAT_S_MASK (1 << 1)
#define REG_STATUS0_ENBAT_LAT_S_MASK (1 << 0)

/**
 * A81415 Status Register 1
 */
#define REG_STATUS1_VREG_F          (1 << 15)
#define REG_STATUS1_VUC_F           (1 << 14)
#define REG_STATUS1_VLDOA_F         (1 << 13)
#define REG_STATUS1_VLDOB_F         (1 << 12)
#define REG_STATUS1_VLDOP_F         (1 << 11)
#define REG_STATUS1_VLDOC_F         (1 << 10)
#define REG_STATUS1_VCP_F           (1 << 9)
#define REG_STATUS1_VUCSEL_S        (1 << 8)
#define REG_STATUS1_BIST_F          (1 << 7)
#define REG_STATUS1_RESETN_VUC_OV   (1 << 6)
#define REG_STATUS1_RESETN_VLDOA_UV (1 << 5)
#define REG_STATUS1_RESETN_VLDOA_OV (1 << 4)
#define REG_STATUS1_RESETN_WD_F     (1 << 3)
#define REG_STATUS1_RESETN_VIN_OV   (1 << 2)
#define REG_STATUS1_RESETN_VLDOC_OV (1 << 1)
#define REG_STATUS1_WSI_F           (1 << 0)

/**
 * A81415 Status Register 2
 */
#define REG_STATUS2_PWWD_CNT_OFFSET       (8)
#define REG_STATUS2_PWWD_CNT_WIDTH        (16)
#define REG_STATUS2_PWWD_CNT_MASK         (0xFFFF)
#define REG_STATUS2_PWWD_CNT(X)           (((X) >> REG_STATUS2_PWWD_CNT_OFFSET) & REG_STATUS2_PWWD_CNT_MASK)
#define REG_STATUS2_QAWD_RETRY_CNT_OFFSET (5)
#define REG_STATUS2_QAWD_RETRY_CNT_WIDTH  (3)
#define REG_STATUS2_QAWD_RETRY_CNT_MASK   (0x7)
#define REG_STATUS2_QAWD_RETRY_CNT(X)                                                              \
    (((X) >> REG_STATUS2_QAWD_RETRY_CNT_OFFSET) & REG_STATUS2_QAWD_RETRY_CNT_MASK)
#define REG_STATUS2_WD_STATE_OFFSET       (2)
#define REG_STATUS2_WD_STATE_WIDTH        (3)
#define REG_STATUS2_WD_STATE_MASK         (0x7)
#define REG_STATUS2_WD_STATE(X)           (((X) >> REG_STATUS2_WD_STATE_OFFSET) & REG_STATUS2_WD_STATE_MASK)
#define REG_STATUS2_WD_STATE_IDLE         (0)
#define REG_STATUS2_WD_STATE_CONFIG       (1)
#define REG_STATUS2_WD_STATE_RESET        (2)
#define REG_STATUS2_WD_STATE_NORMAL       (3)
#define REG_STATUS2_WD_STATE_FLASH        (4)
#define REG_STATUS2_WD_STATE_DISABLED     (5)
#define REG_STATUS2_QAWD_WINDOW_OPEN_MASK (1 << 1)
#define REG_STATUS2_QAWD_CURR_WINDOW_MASK (1 << 0)

/**
 * A81415 Status Register 3
 */
#define REG_STATUS3_QAWD_WINDOW_TIMER_OFFSET (8)
#define REG_STATUS3_QAWD_WINDOW_TIMER_WIDTH  (16)
#define REG_STATUS3_QAWD_WINDOW_TIMER_MASK   (0xFFFF)
#define REG_STATUS3_QAWD_WINDOW_TIMER(X)                                                           \
    (((X) >> REG_STATUS3_QAWD_WINDOW_TIMER_OFFSET) & REG_STATUS3_QAWD_WINDOW_TIMER_MASK)
#define REG_STATUS3_QAWD_TIME_ERR         (1 << 7)
#define REG_STATUS3_QAWD_CODE_ERR         (1 << 6)
#define REG_STATUS3_QAWD_RETRY_CNT_OFFSET (0)
#define REG_STATUS3_QAWD_RETRY_CNT_WIDTH  (6)
#define REG_STATUS3_QAWD_RETRY_CNT_MASK   (0x3F)
#define REG_STATUS3_QAWD_RETRY_CNT(X)                                                              \
    (((X) >> REG_STATUS3_QAWD_RETRY_CNT_OFFSET) & REG_STATUS3_QAWD_RETRY_CNT_MASK)

/**
 * A81415 Diagnostic Register 0
 */
#define REG_DIAGNOSTIC0_VREG_OV  (1 << 15)
#define REG_DIAGNOSTIC0_VREG_UV  (1 << 14)
#define REG_DIAGNOSTIC0_VUC_OV   (1 << 13)
#define REG_DIAGNOSTIC0_VUC_UV   (1 << 12)
#define REG_DIAGNOSTIC0_VLDOA_OV (1 << 11)
#define REG_DIAGNOSTIC0_VLDOA_UV (1 << 10)
#define REG_DIAGNOSTIC0_VLDOB_OV (1 << 9)
#define REG_DIAGNOSTIC0_VLDOB_UV (1 << 8)
#define REG_DIAGNOSTIC0_VLDOP_OV (1 << 7)
#define REG_DIAGNOSTIC0_VLDOP_UV (1 << 6)
#define REG_DIAGNOSTIC0_VLDOC_OV (1 << 5)
#define REG_DIAGNOSTIC0_VLDOC_UV (1 << 4)
#define REG_DIAGNOSTIC0_VCP_OV   (1 << 3)
#define REG_DIAGNOSTIC0_VCP_UV   (1 << 2)
#define REG_DIAGNOSTIC0_TSD_F    (1 << 1)
#define REG_DIAGNOSTIC0_VIN_OV   (1 << 0)

/**
 * A81415 Diagnostic Register 1
 */
#define REG_DIAGNOSTIC1_VUC_OC     (1 << 15)
#define REG_DIAGNOSTIC1_VLDOA_OC   (1 << 14)
#define REG_DIAGNOSTIC1_VLDOB_OC   (1 << 13)
#define REG_DIAGNOSTIC1_VLDOP_OC   (1 << 12)
#define REG_DIAGNOSTIC1_VLDOC_OC   (1 << 11)
#define REG_DIAGNOSTIC1_VREG_OC    (1 << 10)
#define REG_DIAGNOSTIC1_BOOT1_OPEN (1 << 5)
#define REG_DIAGNOSTIC1_BOOT2_OPEN (1 << 4)
#define REG_DIAGNOSTIC1_BOOT1_UV   (1 << 3)
#define REG_DIAGNOSTIC1_BOOT2_UV   (1 << 2)
#define REG_DIAGNOSTIC1_LX1_STG    (1 << 1)
#define REG_DIAGNOSTIC1_LX2_STG    (1 << 0)

/**
 * A81415 Diagnostic Register 2
 */
#define REG_DIAGNOSTIC2_SE          (1 << 15)
#define REG_DIAGNOSTIC2_PWM_F       (1 << 14)
#define REG_DIAGNOSTIC2_CLK_OOR     (1 << 13)
#define REG_DIAGNOSTIC2_WWD_F       (1 << 12)
#define REG_DIAGNOSTIC2_QAWD_F      (1 << 11)
#define REG_DIAGNOSTIC2_PWWD_F      (1 << 10)
#define REG_DIAGNOSTIC2_POE_FAIL    (1 << 9)
#define REG_DIAGNOSTIC2_RESETN_FAIL (1 << 8)
#define REG_DIAGNOSTIC2_RESETN_F    (1 << 5)
#define REG_DIAGNOSTIC2_RESETN_REQ  (1 << 4)
#define REG_DIAGNOSTIC2_RESETN_MCU  (1 << 3)
#define REG_DIAGNOSTIC2_RESETN_PWR  (1 << 2)
#define REG_DIAGNOSTIC2_SPI_CSN_TO  (1 << 0)

/**
 * WD & RESETN Input Keys
 */
#define REG_KEYS_WD_OFFSET                (8)
#define REG_KEYS_WD(X)                    ((X) << REG_KEYS_WD_OFFSET)
#define REG_KEYS_WD_KEY1                  REG_KEYS_WD(0xD3)
#define REG_KEYS_WD_KEY2                  REG_KEYS_WD(0x33)
#define REG_KEYS_WD_FLASH                 REG_KEYS_WD(0xCC)
#define REG_KEYS_WD_CONFIG                REG_KEYS_WD(0xCD)
#define REG_KEYS_WD_RESTART               REG_KEYS_WD(0xCE)
#define REG_KEYS_WD_DISABLE               REG_KEYS_WD(0xCF)
#define REG_KEYS_RESETN_OFFSET            (0)
#define REG_KEYS_RESETN(X)                ((X) << REG_KEYS_RESETN_OFFSET)
#define REG_KEYS_RESETN_KEY1              REG_KEYS_RESETN(0xD4)
#define REG_KEYS_RESETN_KEY2              REG_KEYS_RESETN(0x2B)
#define REG_KEYS_RESETN_RESET             REG_KEYS_RESETN(0x60)
#define REG_KEYS_RESETN_SET(X)            REG_KEYS_RESETN((X) | 0xC0)
#define REG_KEYS_RESETN_SET_VLDOC_OV_MASK (1 << 6)
#define REG_KEYS_RESETN_SET_VUC_OV_MASK   (1 << 5)
#define REG_KEYS_RESETN_SET_VLDOA_UV_MASK (1 << 4)
#define REG_KEYS_RESETN_SET_VLDOA_OV_MASK (1 << 3)
#define REG_KEYS_RESETN_SET_WD_F_MASK     (1 << 2)
#define REG_KEYS_RESETN_SET_VIN_OV_MASK   (1 << 1)

/**
 * Configuration Register 0
 */
#define REG_CONFIG0_VLDOB_EN_MASK    (1 << 14)
#define REG_CONFIG0_VLDOC_EN_MASK    (1 << 13)
#define REG_CONFIG0_VLDOP_EN_OFFSET  (11)
#define REG_CONFIG0_VLDOP_EN_WIDTH   (2)
#define REG_CONFIG0_VLDOP_EN_MASK    (0x3)
#define REG_CONFIG0_VLDOP_EN(X)      (((X) >> REG_CONFIG0_VLDOP_EN_OFFSET) & REG_CONFIG0_VLDOP_EN_MASK)
#define REG_CONFIG0_VLDOP_EN_OFF     (0)
#define REG_CONFIG0_VLDOP_EN_ON      (3)
#define REG_CONFIG0_VLDOA_EN_MASK    (1 << 10)
#define REG_CONFIG0_POE_FORCE_MASK   (1 << 9)
#define REG_CONFIG0_DITH_DIS_MASK    (1 << 8)
#define REG_CONFIG0_TLOW_POE2_OFFSET (4)
#define REG_CONFIG0_TLOW_POE2_WIDTH  (4)
#define REG_CONFIG0_TLOW_POE2_MASK   (0xF)
#define REG_CONFIG0_TLOW_POE2(X)                                                                   \
    (((X) >> REG_CONFIG0_TLOW_POE2_OFFSET) & REG_CONFIG0_TLOW_POE2_MASK)
#define REG_CONFIG0_TDELAY_POE2_OFFSET (0)
#define REG_CONFIG0_TDELAY_POE2_WIDTH  (4)
#define REG_CONFIG0_TDELAY_POE2_MASK   (0xF)
#define REG_CONFIG0_TDELAY_POE2(X)                                                                 \
    (((X) >> REG_CONFIG0_TDELAY_POE2_OFFSET) & REG_CONFIG0_TDELAY_POE2_MASK)

/**
 * Configuration Register 1
 */
#define REG_CONFIG1_ENCAN_LAT_OFFSET (8)
#define REG_CONFIG1_ENCAN_LAT_WIDTH  (8)
#define REG_CONFIG1_ENCAN_LAT_MASK   (0xFF)
#define REG_CONFIG1_ENCAN_LAT(X)                                                                   \
    (((X) >> REG_CONFIG1_ENCAN_LAT_OFFSET) & REG_CONFIG1_ENCAN_LAT_MASK)
#define REG_CONFIG1_ENCAN_LAT_LOW    (0x00)
#define REG_CONFIG1_ENCAN_LAT_HIGH   (0xAA)
#define REG_CONFIG1_ENBAT_LAT_OFFSET (0)
#define REG_CONFIG1_ENBAT_LAT_WIDTH  (8)
#define REG_CONFIG1_ENBAT_LAT_MASK   (0xFF)
#define REG_CONFIG1_ENBAT_LAT(X)                                                                   \
    (((X) >> REG_CONFIG1_ENBAT_LAT_OFFSET) & REG_CONFIG1_ENBAT_LAT_MASK)
#define REG_CONFIG1_ENBAT_LAT_LOW  (0x00)
#define REG_CONFIG1_ENBAT_LAT_HIGH (0x55)

/**
 * Configuration Register 2
 */
#define REG_CONFIG2_VLDOP_OUT_MASK    (1 << 15)
#define REG_CONFIG2_QAWD_TIMERS_MASK  (1 << 11)
#define REG_CONFIG2_QAWD_RETRY_OFFSET (8)
#define REG_CONFIG2_QAWD_RETRY_WIDTH  (3)
#define REG_CONFIG2_QAWD_RETRY_MASK   (0x7)
#define REG_CONFIG2_QAWD_RETRY(X)                                                                  \
    (((X) >> REG_CONFIG2_QAWD_RETRY_OFFSET) & REG_CONFIG2_QAWD_RETRY_MASK)
#define REG_CONFIG2_WD_SEL_OFFSET    (5)
#define REG_CONFIG2_WD_SEL_WIDTH     (3)
#define REG_CONFIG2_WD_SEL_MASK      (0x7)
#define REG_CONFIG2_WD_SEL(X)        (((X) >> REG_CONFIG2_WD_SEL_OFFSET) & REG_CONFIG2_WD_SEL_MASK)
#define REG_CONFIG2_WWD_TIMER_OFFSET (0)
#define REG_CONFIG2_WWD_TIMER_WIDTH  (4)
#define REG_CONFIG2_WWD_TIMER_MASK   (0xF)
#define REG_CONFIG2_WWD_TIMER(X)                                                                   \
    (((X) >> REG_CONFIG2_WWD_TIMER_OFFSET) & REG_CONFIG2_WWD_TIMER_MASK)

/**
 * Configuration Register 3
 */
#define REG_CONFIG3_QAWD_TIMER1_MAX_OFFSET (12)
#define REG_CONFIG3_QAWD_TIMER1_MAX_WIDTH  (4)
#define REG_CONFIG3_QAWD_TIMER1_MAX_MASK   (0xF)
#define REG_CONFIG3_QAWD_TIMER1_MAX(X)                                                             \
    (((X) >> REG_CONFIG3_QAWD_TIMER1_MAX_OFFSET) & REG_CONFIG3_QAWD_TIMER1_MAX_MASK)
#define REG_CONFIG3_QAWD_TIMER1_MIN_OFFSET (8)
#define REG_CONFIG3_QAWD_TIMER1_MIN_WIDTH  (4)
#define REG_CONFIG3_QAWD_TIMER1_MIN_MASK   (0xF)
#define REG_CONFIG3_QAWD_TIMER1_MIN(X)                                                             \
    (((X) >> REG_CONFIG3_QAWD_TIMER1_MIN_OFFSET) & REG_CONFIG3_QAWD_TIMER1_MIN_MASK)
#define REG_CONFIG3_QAWD_TIMER2_MAX_OFFSET (4)
#define REG_CONFIG3_QAWD_TIMER2_MAX_WIDTH  (4)
#define REG_CONFIG3_QAWD_TIMER2_MAX_MASK   (0xF)
#define REG_CONFIG3_QAWD_TIMER2_MAX(X)                                                             \
    (((X) >> REG_CONFIG3_QAWD_TIMER2_MAX_OFFSET) & REG_CONFIG3_QAWD_TIMER2_MAX_MASK)
#define REG_CONFIG3_QAWD_TIMER2_MIN_OFFSET (0)
#define REG_CONFIG3_QAWD_TIMER2_MIN_WIDTH  (4)
#define REG_CONFIG3_QAWD_TIMER2_MIN_MASK   (0xF)
#define REG_CONFIG3_QAWD_TIMER2_MIN(X)                                                             \
    (((X) >> REG_CONFIG3_QAWD_TIMER2_MIN_OFFSET) & REG_CONFIG3_QAWD_TIMER2_MIN_MASK)

/**
 * Configuration Register 4
 */
#define REG_CONFIG4_QAWD_ANS_1_3_OFFSET (10)
#define REG_CONFIG4_QAWD_ANS_1_3_WIDTH  (6)
#define REG_CONFIG4_QAWD_ANS_1_3_MASK   (0x3F)
#define REG_CONFIG4_QAWD_ANS_1_3(X)                                                                \
    (((X) >> REG_CONFIG4_QAWD_ANS_1_3_OFFSET) & REG_CONFIG4_QAWD_ANS_1_3_MASK)
#define REG_CONFIG4_QAWD_ANS_2_4_OFFSET (0)
#define REG_CONFIG4_QAWD_ANS_2_4_WIDTH  (6)
#define REG_CONFIG4_QAWD_ANS_2_4_MASK   (0x3F)
#define REG_CONFIG4_QAWD_ANS_2_4(X)                                                                \
    (((X) >> REG_CONFIG4_QAWD_ANS_2_4_OFFSET) & REG_CONFIG4_QAWD_ANS_2_4_MASK)

/**
 * Configuration Register 5
 */
#define REG_CONFIG5_PWWD_EDGE_TO_OFFSET (14)
#define REG_CONFIG5_PWWD_EDGE_TO_WIDTH  (2)
#define REG_CONFIG5_PWWD_EDGE_TO_MASK   (0x3)
#define REG_CONFIG5_PWWD_EDGE_TO(X)                                                                \
    (((X) >> REG_CONFIG5_PWWD_EDGE_TO_OFFSET) & REG_CONFIG5_PWWD_EDGE_TO_MASK)
#define REG_CONFIG5_PWWD_ACT_TO_OFFSET (12)
#define REG_CONFIG5_PWWD_ACT_TO_WIDTH  (2)
#define REG_CONFIG5_PWWD_ACT_TO_MASK   (0x3)
#define REG_CONFIG5_PWWD_ACT_TO(X)                                                                 \
    (((X) >> REG_CONFIG5_PWWD_ACT_TO_OFFSET) & REG_CONFIG5_PWWD_ACT_TO_MASK)
#define REG_CONFIG5_PWWD_WIN_TOL_OFFSET (10)
#define REG_CONFIG5_PWWD_WIN_TOL_WIDTH  (2)
#define REG_CONFIG5_PWWD_WIN_TOL_MASK   (0x3)
#define REG_CONFIG5_PWWD_WIN_TOL(X)                                                                \
    (((X) >> REG_CONFIG5_PWWD_WIN_TOL_OFFSET) & REG_CONFIG5_PWWD_WIN_TOL_MASK)
#define REG_CONFIG5_PWWD_PW_OFFSET      (8)
#define REG_CONFIG5_PWWD_PW_WIDTH       (2)
#define REG_CONFIG5_PWWD_PW_MASK        (0x3)
#define REG_CONFIG5_PWWD_PW(X)          (((X) >> REG_CONFIG5_PWWD_PW_OFFSET) & REG_CONFIG5_PWWD_PW_MASK)
#define REG_CONFIG5_PWWD_DEC_OFFSET     (6)
#define REG_CONFIG5_PWWD_DEC_WIDTH      (2)
#define REG_CONFIG5_PWWD_DEC_MASK       (0x3)
#define REG_CONFIG5_PWWD_DEC(X)         (((X) >> REG_CONFIG5_PWWD_DEC_OFFSET) & REG_CONFIG5_PWWD_DEC_MASK)
#define REG_CONFIG5_PWWD_INC_OFFSET     (4)
#define REG_CONFIG5_PWWD_INC_WIDTH      (2)
#define REG_CONFIG5_PWWD_INC_MASK       (0x3)
#define REG_CONFIG5_PWWD_INC(X)         (((X) >> REG_CONFIG5_PWWD_INC_OFFSET) & REG_CONFIG5_PWWD_INC_MASK)
#define REG_CONFIG5_PWWD_MAX_OFFSET     (2)
#define REG_CONFIG5_PWWD_MAX_WIDTH      (2)
#define REG_CONFIG5_PWWD_MAX_MASK       (0x3)
#define REG_CONFIG5_PWWD_MAX(X)         (((X) >> REG_CONFIG5_PWWD_MAX_OFFSET) & REG_CONFIG5_PWWD_MAX_MASK)
#define REG_CONFIG5_PWWD_POE_DLY_OFFSET (0)
#define REG_CONFIG5_PWWD_POE_DLY_WIDTH  (2)
#define REG_CONFIG5_PWWD_POE_DLY_MASK   (0x3)
#define REG_CONFIG5_PWWD_POE_DLY(X)                                                                \
    (((X) >> REG_CONFIG5_PWWD_POE_DLY_OFFSET) & REG_CONFIG5_PWWD_POE_DLY_MASK)

/**
 * Configuration Register 6
 */
#define REG_CONFIG6_ABIST_ON_MASK         (1 << 15)
#define REG_CONFIG6_SPI_CSN_TO_EN_MASK    (1 << 10)
#define REG_CONFIG6_SPI_CSN_TO_THR_OFFSET (0)
#define REG_CONFIG6_SPI_CSN_TO_THR_WIDTH  (10)
#define REG_CONFIG6_SPI_CSN_TO_THR_MASK   (0x3F)
#define REG_CONFIG6_SPI_CSN_TO_THR(X)                                                              \
    (((X) >> REG_CONFIG6_SPI_CSN_TO_THR_OFFSET) & REG_CONFIG6_SPI_CSN_TO_THR_MASK)

/**
 * Verify Result Register 0
 */
#define REG_VERIFY_RESULT0_VUC_OV_FAIL_MASK    (1 << 15)
#define REG_VERIFY_RESULT0_VLDOA_OV_FAIL_MASK  (1 << 14)
#define REG_VERIFY_RESULT0_VLDOB_OV_FAIL_MASK  (1 << 13)
#define REG_VERIFY_RESULT0_VLDOP1_OV_FAIL_MASK (1 << 12)
#define REG_VERIFY_RESULT0_VLDOC_OV_FAIL_MASK  (1 << 11)
#define REG_VERIFY_RESULT0_VREG_OV_FAIL_MASK   (1 << 10)
#define REG_VERIFY_RESULT0_VCP_OV_FAIL_MASK    (1 << 9)
#define REG_VERIFY_RESULT0_VIN_OV_FAIL_MASK    (1 << 8)
#define REG_VERIFY_RESULT0_VUC_UV_FAIL_MASK    (1 << 7)
#define REG_VERIFY_RESULT0_VLDOA_UV_FAIL_MASK  (1 << 6)
#define REG_VERIFY_RESULT0_VLDOB_UV_FAIL_MASK  (1 << 5)
#define REG_VERIFY_RESULT0_VLDOP1_UV_FAIL_MASK (1 << 4)
#define REG_VERIFY_RESULT0_VLDOC_UV_FAIL_MASK  (1 << 3)
#define REG_VERIFY_RESULT0_VREG_UV_FAIL_MASK   (1 << 2)
#define REG_VERIFY_RESULT0_VCP_UV_FAIL_MASK    (1 << 1)
#define REG_VERIFY_RESULT0_TSD_BIST_FAIL_MASK  (1 << 0)

/**
 * Verify Result Register 1
 */
#define REG_VERIFY_RESULT1_ABIST_FAIL_MASK    (1 << 15)
#define REG_VERIFY_RESULT1_LBIST_FAIL_MASK    (1 << 14)
#define REG_VERIFY_RESULT1_INT_LOGIC_ERR_MASK (1 << 13)

/**
 * WSI Config Register
 */
#define REG_WSICFG_WSI_TM_EN_MASK    (1 << 15)
#define REG_WSICFG_WSI_FORCE_MASK    (1 << 14)
#define REG_WSICFG_WSI_OC_TH_MASK    (1 << 11)
#define REG_WSICFG_WSI_TD_SEL_OFFSET (8)
#define REG_WSICFG_WSI_TD_SEL_WIDTH  (2)
#define REG_WSICFG_WSI_TD_SEL_MASK   (0x3)
#define REG_WSICFG_WSI_TD_SEL(X)                                                                   \
    (((X) >> REG_WSICFG_WSI_TD_SEL_OFFSET) & REG_WSICFG_WSI_TD_SEL_MASK)
#define REG_WSICFG_WSI_MODE_CONFIG_OFFSET (4)
#define REG_WSICFG_WSI_MODE_CONFIG_WIDTH  (3)
#define REG_WSICFG_WSI_MODE_CONFIG_MASK   (0x7)
#define REG_WSICFG_WSI_MODE_CONFIG(X)                                                              \
    (((X) >> REG_WSICFG_WSI_MODE_CONFIG_OFFSET) & REG_WSICFG_WSI_MODE_CONFIG_MASK)
#define REG_WSICFG_WSI_WD_CONFIG_MASK (1 << 3)
#define REG_WSICFG_WSI_SYNC_MASK      (1 << 2)
#define REG_WSICFG_WSIL_EN_MASK       (1 << 1)
#define REG_WSICFG_WSIH_EN_MASK       (1 << 0)

/**
 * WSI Fault Register
 */
#define REG_WSIFAULT_WSIS_UV_MASK                   (1 << 12)
#define REG_WSIFAULT_WSI_TWARN_MASK                 (1 << 11)
#define REG_WSIFAULT_WSI_TSD_MASK                   (1 << 10)
#define REG_WSIFAULT_WSIL_STG_F_MASK                (1 << 9)
#define REG_WSIFAULT_WSIH_OVC_F_MASK                (1 << 8)
#define REG_WSIFAULT_WSIL_OVC_F_MASK                (1 << 7)
#define REG_WSIFAULT_WSIH_REVERSE_BAT_F_MASK        (1 << 6)
#define REG_WSIFAULT_WSIL_REVERSE_GND_F_MASK        (1 << 5)
#define REG_WSIFAULT_WSI_EXCESSIVE_OFFSET_F_MASK    (1 << 4)
#define REG_WSIFAULT_WSI_OPEN_CUR_F_MASK            (1 << 3)
#define REG_WSIFAULT_WSI_ITH2_GZ_ITH2_EXCEED_F_MASK (1 << 2)
#define REG_WSIFAULT_WSI_ITH1_GZ_F_MASK             (1 << 1)
#define REG_WSIFAULT_VDA_ERR_F_MASK                 (1 << 0)

/**
 * WSI Data Register 0
 */
#define REG_WSIDATA0_WSI_EDGE_COUNT_OFFSET (10)
#define REG_WSIDATA0_WSI_EDGE_COUNT_WIDTH  (6)
#define REG_WSIDATA0_WSI_EDGE_COUNT_MASK   (0x3F)
#define REG_WSIDATA0_WSI_EDGE_COUNT(X)                                                             \
    (((X) >> REG_WSIDATA0_WSI_EDGE_COUNT_OFFSET) & REG_WSIDATA0_WSI_EDGE_COUNT_MASK)
#define REG_WSIDATA0_WSI_TP_OUT_RANGE_MASK  (1 << 9)
#define REG_WSIDATA0_WSI_OFFSET_COMP_OFFSET (0)
#define REG_WSIDATA0_WSI_OFFSET_COMP_WIDTH  (9)
#define REG_WSIDATA0_WSI_OFFSET_COMP_MASK   (0x1F)
#define REG_WSIDATA0_WSI_OFFSET_COMP(X)                                                            \
    (((X) >> REG_WSIDATA0_WSI_OFFSET_COMP_OFFSET) & REG_WSIDATA0_WSI_OFFSET_COMP_MASK)

/**
 * WSI Data Register 1
 */
#define REG_WSIDATA1_VDA_ERR_MASK         (1 << 15)
#define REG_WSIDATA1_VDA_BIT_COUNT_OFFSET (11)
#define REG_WSIDATA1_VDA_BIT_COUNT_WIDTH  (4)
#define REG_WSIDATA1_VDA_BIT_COUNT_MASK   (0xF)
#define REG_WSIDATA1_VDA_BIT_COUNT(X)                                                              \
    (((X) >> REG_WSIDATA1_VDA_BIT_COUNT_OFFSET) & REG_WSIDATA1_VDA_BIT_COUNT_MASK)
#define REG_WSIDATA1_VDA_DATA_OFFSET (2)
#define REG_WSIDATA1_VDA_DATA_WIDTH  (9)
#define REG_WSIDATA1_VDA_DATA_MASK   (0x1FF)
#define REG_WSIDATA1_VDA_DATA(X)                                                                   \
    (((X) >> REG_WSIDATA1_VDA_DATA_OFFSET) & REG_WSIDATA1_VDA_DATA_MASK)
#define REG_WSIDATA1_WSI_STANDSTILL_MASK (1 << 1)
#define REG_WSIDATA1_DATA_READ_MASK      (1 << 0)

uint32_t A81415BuildCommand(uint8_t Command, uint8_t Address, uint16_t Data);

void A81415Transfer(uint32_t Size, uint32_t *Commands);

uint8_t A81415CheckCRC(uint32_t Data);

#if defined(__cplusplus)
}
#endif

#endif // A81415_H
