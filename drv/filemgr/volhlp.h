#ifndef __volhlp_h
#define __volhlp_h

#include "../inc/commonkrnl.h"

#define _VOLUME_DESCRIPTION_LENGTH  0x20

#define _VOLUME_FLAG_NONE           0x0000

typedef struct _VolumeContext
{
    PFLT_INSTANCE           m_Instance;
    ULONG                   m_Flags;
    STORAGE_BUS_TYPE        m_BusType;
    DEVICE_REMOVAL_POLICY   m_RemovablePolicy;
    UNICODE_STRING          m_DeviceId;
    UCHAR                   m_VendorId[_VOLUME_DESCRIPTION_LENGTH];
    UCHAR                   m_ProductId[_VOLUME_DESCRIPTION_LENGTH];
    UCHAR                   m_ProductRevisionLevel[_VOLUME_DESCRIPTION_LENGTH];
    UCHAR                   m_VendorSpecific[_VOLUME_DESCRIPTION_LENGTH];
} VolumeContext, *PVolumeContext;

__checkReturn
NTSTATUS
FillVolumeProperties (
     __in PCFLT_RELATED_OBJECTS FltObjects,
    __in PVolumeContext VolumeCtx
    );

__checkReturn
__drv_maxIRQL( APC_LEVEL )
NTSTATUS
GetInstanceFromFileObject (
    __in PFLT_FILTER FltFilter,
    __in PFILE_OBJECT FileObject,
    __out PFLT_INSTANCE *RetInstance
    );
    
#endif // __volhlp_h