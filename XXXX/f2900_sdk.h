#ifndef VIDEOCAPTURE_SDK_H
#define VIDEOCAPTURE_SDK_H

#define DLL_API_EXPORT
#ifdef DLL_API_EXPORT
#define NENGTONG_API    __declspec(dllexport)
#else
#define NENGTONG_API    __declspec(dllimport)
#endif

#define uchar unsigned char

typedef enum {TASK_PREVIEW, TASK_STORAGE, TASK_MAX_NUM} TASK_T;
typedef enum {CHANN_NO_INPUT = 0, CHANN_NORMAL_INPUT} CHANN_STATUS_T;

typedef enum {VIDEOPROCAMP_BRIGHTNESS, VIDEOPROCAMP_CONTRAST, VIDEOPROCAMP_HUE,
              VIDEOPROCAMP_SATURATION, VIDEOPROCAMP_SHARPNESS, VIDEOPROCAMP_MAX_NUM
             } VIDEO_PROCAMP_T;
typedef enum {VIDEO_OUTPUT_FMT_YUV = 0, VIDEO_OUTPUT_FMT_MPEG2 = 1,
              VIDEO_OUTPUT_FMT_MAX_NUM
             } VIDEO_OUTPUT_FORMAT_T;
//ARINC429 波特率
typedef enum {BAUDRATE_100KPS, BAUDRATE_12_5_KPS} BAUDRATE_T;

typedef enum
{
    BAUDRATE_9600, BAUDRATE_14400, BAUDRATE_19200, BAUDRATE_38400,
    BAUDRATE_56000, BAUDRATE_57600, BAUDRATE_115200, BAUDRATE_128000
} BAUDRATE_NORMAL_T;
typedef enum {CC_OUT_SYN_SIGNAL, CC_PIXEL_RESET, CC_PREFIX_SIGNAL, CC_RESERVE_SIGNAL} CAMERA_CONTROL_T;
typedef enum {RECV_FIFO_EMPTY, RECV_FIFO_NO_EMPTY, SEND_FIFO_FULL, SEND_FIFO_NO_FULL, FIFO_STATUS_INVALID} FIFO_STATUS_T;

typedef enum {VIDEO_CONVERT_STOP, VIDEO_CONVERT_START} VIDEO_CONVERT_ENABLE_STATUS_T;
typedef enum {AV_PORT, HDSDI1_PORT, HDSDI2_PORT, CAMERA_LINK1_PORT, CAMERA_LINK2_PORT} VIDEO_CONVERT_SRC;
typedef enum {NULL_FMT, AV_FMT, HDSDI_FMT, CAMERA_LINK_FMT} VIDEO_CONVERT_DST;
typedef enum {CAMERA_LINK_DATA_NONREADY, CAMERA_LINK_DATA_READY} CAMERA_LINK_DATA_STATUS_T;

typedef enum {RS422_ASYN1_PORT, RS422_ASYN2_PORT, RS422_ASYN3_PORT, RS422_ASYN4_PORT,
              RS422_ASYN5_PORT, RS422_ASYN6_PORT, RS422_SYN1_PORT, RS422_ASYN1_EXTRA_SERIAL, RS422_ASYN2_EXTRA_SERIAL, MAX_SERIAL_PORT_NUM
             } RS422_SERIAL_TYPE_T;
typedef enum {CAMERALINK1_PORT, CAMERALINK2_PORT} CAMERALINK_PORT_TYPE_T;
/********************************* SDK Interface ******************************************************/
#ifdef __cplusplus
extern "C" {
#endif

NENGTONG_API int __stdcall InitMediaDll();
NENGTONG_API int __stdcall UnInitMediaDll();

NENGTONG_API int __stdcall GetSdkVersion(long long* plVersion);
NENGTONG_API int __stdcall GetHardwareNum(int *piCardNum);
NENGTONG_API int __stdcall ResetHardware(int iCardId);
NENGTONG_API int __stdcall GetChannNum(int* piChannNum, int* piEnabledChannNum);
NENGTONG_API int __stdcall StartStreamCapture(int iChann, TASK_T eTask);
NENGTONG_API int __stdcall StopStreamCapture(int iChann);
NENGTONG_API int __stdcall CheckStreamStatus(int iChann, CHANN_STATUS_T * iStatus);
NENGTONG_API int __stdcall GetVideoData(int iChann, int *height, int *width, uchar * pBuff, int iExpectLen, int* iCurrLen);     //_MODIFY_7_18_2016添加对于所取数据大小的获取uiCurrLen

#if 0
NENGTONG_API int __stdcall GetVideoProp(int iChann, VIDEO_PROCAMP_T enVidProCamp, int* piMaxValue,
                                        int* piMinValue, int* piDefValue);
NENGTONG_API int __stdcall SetVideoProp(int iChann, VIDEO_PROCAMP_T enVidProCamp, int iPropValue);
NENGTONG_API int __stdcall GetVideoFmt(int iChann, VIDEO_OUTPUT_FORMAT_T * VidOutputFmt);
NENGTONG_API int __stdcall SetVideoFmt(int iChann, VIDEO_OUTPUT_FORMAT_T enVidOutputFmt);
NENGTONG_API int __stdcall GetVideoSize(int iChann, int* piVidWidth, int* piVidHeight);

#endif // 摒弃接口


//CAMERALINK oper
NENGTONG_API int __stdcall OpenCamerLinkPort(CAMERALINK_PORT_TYPE_T ePortType, BAUDRATE_NORMAL_T eBaudrate, CAMERA_CONTROL_T eCameraControl);
NENGTONG_API int __stdcall CheckCamerLinkStatus(CAMERALINK_PORT_TYPE_T ePortType, CAMERA_LINK_DATA_STATUS_T* isReady);
NENGTONG_API int __stdcall CloseCamerLinkPort(CAMERALINK_PORT_TYPE_T ePortType);
NENGTONG_API int __stdcall WriteCamerLinkPort(CAMERALINK_PORT_TYPE_T ePortType, uchar * pBuf, int iLen);
NENGTONG_API int __stdcall ReadCamerLinkPort(CAMERALINK_PORT_TYPE_T ePortType, uchar * pBuf, int iLen, int* pCurrLen);

//视频转换配置
NENGTONG_API int __stdcall SetVideoConvertConfig(VIDEO_CONVERT_SRC enVideoSrc, VIDEO_CONVERT_DST enVideoDst);
NENGTONG_API int __stdcall GetVideoConvertConfig(VIDEO_CONVERT_SRC enVideoSrc, VIDEO_CONVERT_DST* enVideoDst);
NENGTONG_API int __stdcall ChangeVideoConvertStatus(VIDEO_CONVERT_ENABLE_STATUS_T eConvertOper);

//ARINC429 oper
NENGTONG_API int __stdcall OpenARINC429Port(BAUDRATE_T eBaudRate);
NENGTONG_API int __stdcall SetA429Baudrate(BAUDRATE_T eBoadRate);
NENGTONG_API int __stdcall GetA429Baudrate(BAUDRATE_T* peBaudRate);
NENGTONG_API int __stdcall CheckARINC429Status(FIFO_STATUS_T* peFIFOStatus);
NENGTONG_API int __stdcall ReadARINC429Port(unsigned int* pBuf, int iLen, int* pCurrLen);
NENGTONG_API int __stdcall WriteARINC429Port(unsigned int* pBuf, int iLen);
NENGTONG_API int __stdcall CloseARINC429Port();

//RS422 oper
NENGTONG_API int __stdcall OpenRS422Port(RS422_SERIAL_TYPE_T ePortType, BAUDRATE_NORMAL_T eBaudRate);
NENGTONG_API int __stdcall CheckRS422Status(RS422_SERIAL_TYPE_T ePortType, FIFO_STATUS_T* peFIFOStatus, FIFO_STATUS_T* peSendStatus);
NENGTONG_API int __stdcall ReadRS422Port(RS422_SERIAL_TYPE_T ePortType, uchar* pBuf, int iLen, int* pCurrLen);
NENGTONG_API int __stdcall WriteRS422Port(RS422_SERIAL_TYPE_T ePortType, uchar* pBuf, int iLen);
NENGTONG_API int __stdcall CloseRS422Port(RS422_SERIAL_TYPE_T ePortType);

//CAN oper
NENGTONG_API int __stdcall OpenCANPort();
NENGTONG_API int __stdcall CheckCANStatus(FIFO_STATUS_T* peRecvStatus, FIFO_STATUS_T* peSendStatus);
NENGTONG_API int __stdcall ReadCANPort(uchar* pBuff, int iLen, int* pCurrLen);
NENGTONG_API int __stdcall WriteCANPort(uchar* pBuff, int iLen);
NENGTONG_API int __stdcall CloseCANPort();

#ifdef DEBUG_DMA
void * __stdcall getWDCDeviceHandle();
#endif // DEBUG_DMA

#ifdef __cplusplus
}
#endif
#endif