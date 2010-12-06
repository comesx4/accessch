#pragma once
#include "../inc/fltsystem.h"

// �������� ������ �����
NTSTATUS
PortCreate (
    __in PFLT_FILTER Filter,
    __deref_out_opt PFLT_PORT* Port
    );

// cb-������� ��������� ���������� � ������
NTSTATUS
PortConnect (
    __in PFLT_PORT ClientPort,
    __in_opt PVOID ServerPortCookie,
    __in_bcount_opt(SizeOfContext) PVOID ConnectionContext,
    __in ULONG SizeOfContext,
    __deref_out_opt PVOID *ConnectionCookie
    );

// cb-������� ���������� ����� �� ��������
void
PortDisconnect (
    __in PVOID ConnectionCookie
    );

// cb-������� ������� �� �����
NTSTATUS
PortMessageNotify (
    __in PVOID ConnectionCookie,
    __in_bcount_opt(InputBufferSize) PVOID InputBuffer,
    __in ULONG InputBufferSize,
    __out_bcount_part_opt(OutputBufferSize,*ReturnOutputBufferLength) PVOID OutputBuffer,
    __in ULONG OutputBufferSize,
    __out PULONG ReturnOutputBufferLength
    );

//+ �������������� � ������

// ������ �����
__checkReturn
NTSTATUS
PortQueryConnected (
    __drv_when(return==0, __deref_out_opt __drv_valueIs(!=0)) PFLT_PORT* Port
    );

// ������������ �����
void
PortRelease (
    __in_opt PFLT_PORT Port
    );

// �������� �������
__checkReturn
NTSTATUS
PortAllocateMessage (
    __in EventData *Event,
    __in QueuedItem* QueuedItem,
    __drv_when(return==0, __out_opt __drv_valueIs(!=0)) PVOID* Message,
    __out_opt PULONG MessageSize,
    __in PARAMS_MASK ParamsMask
    );

// ������������ �������
void
PortReleaseMessage (
    __in_opt PVOID Message
    );

// ������� ��������� � ����
__checkReturn
NTSTATUS
PortAskUser (
    __in EventData *Event,
    __in PARAMS_MASK ParamsMask,
    __inout VERDICT* Verdict
    );
