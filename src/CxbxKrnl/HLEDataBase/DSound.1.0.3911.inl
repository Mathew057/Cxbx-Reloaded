// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->DSound.1.0.3911.inl
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2017 RadWolfie
// *
// *  All rights reserved
// *
// ******************************************************************


// ******************************************************************
// * DirectSoundEnterCriticalSection
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(DirectSoundEnterCriticalSection, 3911, 7,

    XREF_DirectSoundEnterCriticalSection,
    XRefZero)

        { 0x02, 0xB6 },
        { 0x06, 0x00 },
        { 0x0A, 0x74 },
        { 0x0E, 0xC3 },
        { 0x14, 0xFF },
        { 0x1A, 0x33 },
        { 0x1B, 0xC0 },
OOVPA_END;

// ******************************************************************
// * IDirectSound_CreateSoundBuffer
// ******************************************************************
//TODO: Need to make CDirectSound_CreateSoundBuffer OOVPA for 3911 and newer.
OOVPA_XREF(IDirectSound_CreateSoundBuffer, 3911, 12,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSound_CreateSoundBuffer+0x1D : call [CDirectSound::CreateSoundBuffer]
        XREF_ENTRY( 0x1D, XREF_DSCREATESOUNDBUFFER ),

        // IDirectSound_CreateSoundBuffer+0x04 : mov eax, [esp+8]
        { 0x04, 0x8B },
        { 0x05, 0x44 },
        { 0x06, 0x24 },
        { 0x07, 0x08 },

        // IDirectSound_CreateSoundBuffer+0x12 : add eax, 0xFFFFFFF8
        { 0x12, 0x83 },
        { 0x13, 0xC0 },
        { 0x14, 0xF8 },

        // IDirectSound_CreateSoundBuffer+0x17 : sbb ecx, ecx
        { 0x17, 0x1B },
        { 0x18, 0xC9 },

        // IDirectSound_CreateSoundBuffer+0x21 : retn 0x10
        { 0x21, 0xC2 },
        { 0x22, 0x10 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_AddRef
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(IDirectSoundBuffer_AddRef, 3911, 11)

        // IDirectSoundBuffer_AddRef+0x04 : lea ecx, [eax-0x1C]
        { 0x04, 0x8D },
        { 0x05, 0x48 },
        { 0x06, 0xE4 },

        // IDirectSoundBuffer_AddRef+0x07 : neg eax; sbb eax, eax
        { 0x07, 0xF7 },
        { 0x08, 0xD8 },
        { 0x09, 0x1B },
        { 0x0A, 0xC0 },

        // IDirectSoundBuffer_AddRef+0x10 : call dword ptr [ecx+0x04]
        { 0x10, 0xFF },
        { 0x11, 0x51 },
        { 0x12, 0x04 },
    
        // IDirectSoundBuffer_AddRef+0x13 : ret 4
        { 0x13, 0xC2 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_Release
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(IDirectSoundBuffer_Release, 3911, 11)

        // IDirectSoundBuffer_Release+0x04 : lea ecx, [eax-0x1C]
        { 0x04, 0x8D },
        { 0x05, 0x48 },
        { 0x06, 0xE4 },

        // IDirectSoundBuffer_Release+0x07 : neg eax; sbb eax, eax
        { 0x07, 0xF7 },
        { 0x08, 0xD8 },
        { 0x09, 0x1B },
        { 0x0A, 0xC0 },

        // IDirectSoundBuffer_Release+0x10 : call dword ptr [ecx+0x08]
        { 0x10, 0xFF },
        { 0x11, 0x51 },
        { 0x12, 0x08 },

        // IDirectSoundBuffer_Release+0x13 : ret 4
        { 0x13, 0xC2 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_Unlock
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(IDirectSoundBuffer_Unlock, 3911, 5)

    // IDirectSoundBuffer_Unlock+0x00 : xor eax, eax
    { 0x00, 0x33 },
    { 0x01, 0xC0 },

    // IDirectSoundBuffer_Unlock+0x02 : ret 14h
    { 0x02, 0xC2 },
    { 0x03, 0x14 },
    { 0x04, 0x00 }
OOVPA_END;
#if 0 // Cannot be used since this OOVPA does produce false detection. Use it only for as a model understanding.
// ******************************************************************
// * IDirectSound_SetCooperativeLevel
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_NO_XREF(IDirectSound_SetCooperativeLevel, 3911, 5)

    // IDirectSound_SetCooperativeLevel+0x00 : xor eax, eax
    { 0x00, 0x33 },
    { 0x01, 0xC0 },

    // IDirectSound_SetCooperativeLevel+0x02 : ret 0Ch
    { 0x02, 0xC2 },
    { 0x03, 0x0C },
    { 0x04, 0x00 }
OOVPA_END;
#endif
// ******************************************************************
// * CMcpxVoiceClient_SetVolume
// ******************************************************************
OOVPA_XREF(CMcpxVoiceClient_SetVolume, 3911, 11,

    XREF_CMcpxVoiceClient_SetVolume,
    XRefZero)

        // CMcpxVoiceClient_SetVolume+0x26 : mov ecx, [esi+0xE0]
        { 0x26, 0x8B },
        { 0x27, 0x8E },
        { 0x28, 0xE0 },
        { 0x29, 0x00 },

        // CMcpxVoiceClient_SetVolume+0x2F : movzx ecx, word ptr [ecx+2]
        { 0x2F, 0x0F },
        { 0x30, 0xB7 },
        { 0x31, 0x49 },
        { 0x32, 0x02 },

        // CMcpxVoiceClient_SetVolume+0x35 : dec ecx; sar ecx, 1
        { 0x35, 0x49 },
        { 0x36, 0xD1 },
        { 0x37, 0xF9 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundVoice_SetVolume
// ******************************************************************
OOVPA_XREF(CDirectSoundVoice_SetVolume, 3911, 11,

    XREF_CDirectSoundVoice_SetVolume,
    XRefOne)

        XREF_ENTRY( 0x1E, XREF_CMcpxVoiceClient_SetVolume ),

        //CDirectSoundVoice_SetVolume+0x00 : push esi
        { 0x00, 0x56 },

        //CDirectSoundVoice_SetVolume+0x11 : mov eax, dword ptr [ecx+18h]
        { 0x11, 0x8B },
        { 0x12, 0x41 },
        { 0x13, 0x18 },

        //CDirectSoundVoice_SetVolume+0x1A : mov ecx, dword ptr [ecx+14h]
        { 0x1A, 0x8B },
        { 0x1B, 0x49 },
        { 0x1C, 0x14 },

        //CDirectSoundVoice_SetVolume+0x1D : call CMcpxVoiceClient_SetVolume
        { 0x1D, 0xE8 },

        //CDirectSoundVoice_SetVolume+0x37 : ret 8
        { 0x37, 0xC2 },
        { 0x38, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetVolume
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_SetVolume, 3911, 10,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_SetVolume+0x15 : call [CDirectSoundVoice_SetVolume]
        XREF_ENTRY( 0x15, XREF_CDirectSoundVoice_SetVolume),

        // IDirectSoundBuffer_SetVolume+0x04 : push [esp+0x08]
        { 0x04, 0xFF },
        { 0x05, 0x74 },
        { 0x06, 0x24 },
        { 0x07, 0x08 },

        // IDirectSoundBuffer_SetVolume+0x0A : add eax, 0xFFFFFFE4
        { 0x0A, 0x83 },
        { 0x0B, 0xC0 },
        { 0x0C, 0xE4 },

        // IDirectSoundBuffer_SetVolume+0x19 : retn 0x08
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * CMcpxBuffer_Stop
// ******************************************************************
OOVPA_XREF(CMcpxBuffer_Stop, 3911, 10,

	XREF_CMcpxBuffer_Stop,
    XRefZero)

        // CMcpxBuffer_Stop+0x08 : or eax, dword ptr [esp+10h]
        { 0x08, 0x0B },
        { 0x09, 0x44 },
        { 0x0A, 0x24 },
        { 0x0B, 0x10 },

        // CMcpxBuffer_Stop+0x19 : push 3
        { 0x19, 0x6A },
        { 0x1A, 0x03 },

        // CMcpxBuffer_Stop+0x24 : test [esp+10h], 2
        { 0x24, 0x8B },
        { 0x25, 0xCE },

        // CMcpxBuffer_Stop+0x31 : retn 0x08
        { 0x31, 0xC2 },
        { 0x32, 0x08 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_StopEx
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_StopEx, 3911, 11,

    XREF_CDirectSoundBuffer_StopEx,
    XRefOne)

        XREF_ENTRY( 0x39, XREF_CMcpxBuffer_Stop ),

        // CDirectSoundBuffer_StopEx+0x0F : test al, 3
        { 0x0F, 0xA8 },
        { 0x10, 0x03 },


        // CDirectSoundBuffer_StopEx+0x15 : and eax, 1
        { 0x15, 0x83 },
        { 0x16, 0xE0 },
        { 0x17, 0x01 },

        // CDirectSoundBuffer_StopEx+0x32 : push dword ptr [ebp+0Ch]
        { 0x32, 0xFF },
        { 0x33, 0x75 },
        { 0x34, 0x0C },

        // CDirectSoundBuffer_StopEx+0x53 : retn 0x10
        { 0x53, 0xC2 },
        { 0x54, 0x10 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_StopEx
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_StopEx, 3911, 9,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_StopEx+0x1D : call [CDirectSoundBuffer::StopEx]
        XREF_ENTRY( 0x1D, XREF_CDirectSoundBuffer_StopEx ), 

        { 0x03, 0x10 },
        { 0x08, 0xFF },
        { 0x0D, 0xC8 },
        { 0x12, 0x83 },
        { 0x17, 0x1B },
        { 0x1C, 0xE8 },
        { 0x21, 0xC2 },
        { 0x22, 0x10 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_Stop
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_Stop, 3911, 13,

    XREF_CDirectSoundBuffer_Stop,
    XRefOne)

        XREF_ENTRY( 0x14, XREF_CDirectSoundBuffer_StopEx ),

        // CDirectSoundBuffer_Stop+0x07 : mov eax, 0x80004005
        { 0x07, 0x6A },
        { 0x08, 0x00 },
        { 0x09, 0x6A },
        { 0x0A, 0x00 },
        { 0x0B, 0x6A },
        { 0x0C, 0x00 },

        // CDirectSoundBuffer_Stop+0x1A : mov ebx, eax; jz +0x0B
        { 0x1A, 0x8B },
        { 0x1B, 0xD8 },
        { 0x1C, 0x74 },
        { 0x1D, 0x0B },

        // CDirectSoundBuffer_Stop+0x2D : retn 0x04
        { 0x2D, 0xC2 },
        { 0x2E, 0x04 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_Stop
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_Stop, 3911, 12,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_Stop+0x11 : call [CDirectSoundBuffer::Stop]
        XREF_ENTRY( 0x11, XREF_CDirectSoundBuffer_Stop ), 

        // IDirectSoundBuffer_Stop+0x00 : mov eax, [esp+arg_0]
        { 0x00, 0x8B },
        { 0x01, 0x44 },
        { 0x02, 0x24 },
        { 0x03, 0x04 },

        // IDirectSoundBuffer_Stop+0x04 : mov ecx, eax
        { 0x04, 0x8B },
        { 0x05, 0xC8 },

        // IDirectSoundBuffer_Stop+0x06 : add eax, 0x0FFFFFFE4
        { 0x06, 0x83 },
        { 0x07, 0xC0 },
        { 0x08, 0xE4 },

        // IDirectSoundBuffer_Stop+0x15 : retn 4
        { 0x16, 0x04 },
        { 0x17, 0x00 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetLoopRegion
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
//TODO: Need to make CDirectSoundBuffer_SetLoopRegion OOVPA for 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_SetLoopRegion, 3911, 9,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x19, XREF_CDirectSoundBuffer_SetLoopRegion ),

        { 0x02, 0x24 },
        { 0x06, 0x24 },
        { 0x0A, 0xFF },
        { 0x0E, 0x83 },
        { 0x12, 0xD9 },
        { 0x16, 0xC8 },
        { 0x1D, 0xC2 },
        { 0x1E, 0x0C },
OOVPA_END;

// ******************************************************************
// * CMcpxBuffer_Play
// ******************************************************************
OOVPA_XREF(CMcpxBuffer_Play, 3911, 9,

    XREF_CMcpxBuffer_Play,
    XRefZero)

        { 0x06, 0x56 },
        { 0x0E, 0xF1 },
        { 0x18, 0x75 },
        { 0x19, 0x08 },
        { 0x1A, 0x6A },
        { 0x1B, 0x02 },
        { 0x26, 0x75 },
        { 0x2F, 0x8B },
        { 0x36, 0xC2 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_PlayEx
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_PlayEx, 3911, 9,

    XREF_CDirectSoundBuffer_PlayEx,
    XRefOne)

        XREF_ENTRY( 0x21, XREF_CMcpxBuffer_Play ),

        { 0x08, 0xF0 },

        { 0x13, 0x24 },
        { 0x17, 0x24 },
        { 0x1B, 0x24 },

        { 0x25, 0x85 },
        { 0x27, 0x8B },


        { 0x3A, 0xC2 },
        { 0x3B, 0x10 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_Play
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_Play, 3911, 8,

    XREF_CDirectSoundBuffer_Play,
    XRefOne)

        XREF_ENTRY( 0x16, XREF_CDirectSoundBuffer_PlayEx ),

        { 0x07, 0xFF },
        { 0x0C, 0xF0 },
        { 0x13, 0x24 },
        { 0x1A, 0x85 },
        { 0x25, 0xFF },
        { 0x2B, 0x8B },
        { 0x2F, 0xC2 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_Play
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_Play, 3911, 16,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_Play+0x1D : call CDirectSoundBuffer::Play
        XREF_ENTRY( 0x1D, XREF_CDirectSoundBuffer_Play ),

        // IDirectSoundBuffer_Play+0x00 : push [esp+0x10]
        { 0x00, 0xFF },
        { 0x01, 0x74 },
        { 0x02, 0x24 },
        { 0x03, 0x10 },

        // IDirectSoundBuffer_Play+0x04 : mov eax, [esp+4+arg_0]
        { 0x04, 0x8B },
        { 0x05, 0x44 },
        { 0x06, 0x24 },
        { 0x07, 0x08 },

        // IDirectSoundBuffer_Play+0x12 : and eax, [0xFFFFFFE4]
        { 0x12, 0x83 },
        { 0x13, 0xC0 },
        { 0x14, 0xE4 },

        // IDirectSoundBuffer_Play+0x17 : sbb ecx, ecx
        { 0x17, 0x1B },
        { 0x18, 0xC9 },

        // IDirectSoundBuffer_Play+0x21 : retn 0x10
        { 0x21, 0xC2 },
        { 0x22, 0x10 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_PlayEx
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_PlayEx, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x1D, XREF_CDirectSoundBuffer_PlayEx ),

        { 0x03, 0x10 },
        { 0x08, 0xFF },
        { 0x0D, 0xC8 },
        { 0x12, 0x83 },
        { 0x17, 0x1B },
        { 0x1C, 0xE8 },
        { 0x21, 0xC2 },
OOVPA_END;

// ******************************************************************
// * CMcpxBuffer_GetCurrentPosition
// ******************************************************************
OOVPA_XREF(CMcpxBuffer_GetCurrentPosition, 3911, 11,

    XREF_CMcpxBuffer_GetCurrentPosition,
    XRefZero)

        // CMcpxBuffer_GetCurrentPosition+0x12 : mov eax, [esi+0x18]
        { 0x12, 0x8B },
        { 0x13, 0x46 },
        { 0x14, 0x18 },

        // CMcpxBuffer_GetCurrentPosition+0x1A : jnz +0x79
        { 0x1A, 0x75 },
        { 0x1B, 0x79 },

        // CMcpxBuffer_GetCurrentPosition+0x8E : div dword ptr [ecx+0x4C]
        { 0x8E, 0xF7 },
        { 0x8F, 0x71 },
        { 0x90, 0x4C },

        // CMcpxBuffer_GetCurrentPosition+0xC8 : retn 0x08
        { 0xC8, 0xC2 },
        { 0xC9, 0x08 },
        { 0xCA, 0x00 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_GetCurrentPosition
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_GetCurrentPosition, 3911, 9,

    XREF_CDirectSoundBuffer_GetCurrentPosition,
    XRefOne)

        // CDirectSoundBuffer_GetCurrentPosition+0x19 : call [CMcpxBuffer::GetCurrentPosition]
        XREF_ENTRY( 0x19, XREF_CMcpxBuffer_GetCurrentPosition), 

        // CDirectSoundBuffer_GetCurrentPosition+0x0D : mov eax, [esp+0x10]
        { 0x0D, 0x8B },
        { 0x0E, 0x44 },
        { 0x0F, 0x24 },
        { 0x10, 0x10 },

        // CDirectSoundBuffer_GetCurrentPosition+0x21 : jz +0x0B
        { 0x21, 0x74 },
        { 0x22, 0x0B },

        // CDirectSoundBuffer_GetCurrentPosition+0x32 : retn 0x0C
        { 0x32, 0xC2 },
        { 0x33, 0x0C },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_GetCurrentPosition
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_GetCurrentPosition, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_GetCurrentPosition+0x19 : call [CDirectSoundBuffer::GetCurrentPosition]
        XREF_ENTRY( 0x19, XREF_CDirectSoundBuffer_GetCurrentPosition), 

        // IDirectSoundBuffer_GetCurrentPosition+0x0E : add eax, 0xFFFFFFE4
        { 0x0E, 0x83 },
        { 0x0F, 0xC0 },
        { 0x10, 0xE4 },

        // IDirectSoundBuffer_GetCurrentPosition+0x13 : sbb ecx, ecx
        { 0x13, 0x1B },
        { 0x14, 0xC9 },

        // IDirectSoundBuffer_GetCurrentPosition+0x15 : and ecx, eax
        { 0x15, 0x23 },
        { 0x16, 0xC8 },
OOVPA_END;

// ******************************************************************
// * CMcpxBuffer_GetStatus
// ******************************************************************
OOVPA_XREF(CMcpxBuffer_GetStatus, 3911, 13,

	XREF_CMcpxBuffer_GetStatus,
    XRefZero)

        // CMcpxBuffer_GetStatus+0x10 : mov eax, [ebp+0x08]
        { 0x10, 0x8B },
        { 0x11, 0x45 },
        { 0x12, 0x08 },

        // CMcpxBuffer_GetStatus+0x16 : xor ecx, ecx; inc ecx
        { 0x16, 0x33 },
        { 0x17, 0xC9 },
        { 0x18, 0x41 },

        // CMcpxBuffer_GetStatus+0x1C : jz +0x17
        { 0x1C, 0x74 },
        { 0x1D, 0x17 },

        // CMcpxBuffer_GetStatus+0x2F : mov [eax], 5
        { 0x2F, 0xC7 },
        { 0x30, 0x00 },
        { 0x31, 0x05 },

        // CMcpxBuffer_GetStatus+0x48 : retn 0x04
        { 0x48, 0xC2 },
        { 0x49, 0x04 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundBuffer_GetStatus
// ******************************************************************
OOVPA_XREF(CDirectSoundBuffer_GetStatus, 3911, 10,

    XREF_CDirectSoundBuffer_GetStatus,
    XRefOne)

        // CDirectSoundBuffer_GetStatus+0x15 : call [CMcpxBuffer::GetStatus]
        XREF_ENTRY( 0x15, XREF_CMcpxBuffer_GetStatus),

        // CDirectSoundBuffer_GetStatus+0x07 : push [esp+0x10]
        { 0x07, 0xFF },
        { 0x08, 0x74 },
        { 0x09, 0x24 },
        { 0x0A, 0x10 },

        // CDirectSoundBuffer_GetStatus+0x11 : mov ecx, [eax+0x20]
        { 0x11, 0x8B },
        { 0x12, 0x48 },
        { 0x13, 0x20 },

        // CDirectSoundBuffer_GetStatus+0x2E : retn 0x08
        { 0x2E, 0xC2 },
        { 0x2F, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_GetStatus
// ******************************************************************
//Generic OOVPA as of 3911 and newer.
OOVPA_XREF(IDirectSoundBuffer_GetStatus, 3911, 10,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_GetStatus+0x15 : call [CDirectSoundBuffer::GetStatus]
        XREF_ENTRY( 0x15, XREF_CDirectSoundBuffer_GetStatus ),

        // IDirectSoundBuffer_GetStatus+0x04 : push [esp+0x08]
        { 0x04, 0xFF },
        { 0x05, 0x74 },
        { 0x06, 0x24 },
        { 0x07, 0x08 },

        // IDirectSoundBuffer_GetStatus+0x0A : add eax, 0xFFFFFFE4
        { 0x0A, 0x83 },
        { 0x0B, 0xC0 },
        { 0x0C, 0xE4 },

        // IDirectSoundBuffer_GetStatus+0x19 : retn 0x08
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * CMcpxVoiceClient::SetFilter
// ******************************************************************
OOVPA_XREF(CMcpxVoiceClient_SetFilter, 3911, 12,

    XREF_CMcpxVoiceClient_SetFilter,
    XRefZero)

        { 0x0E, 0xE8 },
        { 0x1F, 0x6A },

        { 0x73, 0x00 },
        { 0x74, 0xF6 },
        { 0x75, 0x47 },
        { 0x76, 0x0C },
        { 0x77, 0x10 },
        { 0x78, 0x8B },
        { 0x79, 0x7D },
        { 0x7A, 0xE0 },

        { 0xA6, 0x8B },
        { 0xA7, 0xE0 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundVoice::SetFilter
// ******************************************************************
OOVPA_XREF(CDirectSoundVoice_SetFilter, 3911, 10,

    XREF_CDirectSoundVoice_SetFilter,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CMcpxVoiceClient_SetFilter ),

        { 0x01, 0x57 },
        { 0x0D, 0x8B },
        { 0x0E, 0x44 },
        { 0x0F, 0x24 },
        { 0x10, 0x10 },
        { 0x11, 0x8B },
        { 0x12, 0x48 },
        { 0x2E, 0xC2 },
        { 0x2F, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetFilter
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_SetFilter, 3911, 10,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSoundBuffer_SetFilter+0x15 : call [CDirectSoundVoice_SetFilter]
        XREF_ENTRY( 0x15, XREF_CDirectSoundVoice_SetFilter),

        // IDirectSoundBuffer_SetFilter+0x04 : push [esp+0x08]
        { 0x04, 0xFF },
        { 0x05, 0x74 },
        { 0x06, 0x24 },
        { 0x07, 0x08 },

        // IDirectSoundBuffer_SetFilter+0x0A : add eax, 0xFFFFFFE4
        { 0x0A, 0x83 },
        { 0x0B, 0xC0 },
        { 0x0C, 0xE4 },

        // IDirectSoundBuffer_SetFilter+0x19 : retn 0x08
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * CMcpxVoiceClient::SetLFO
// ******************************************************************
OOVPA_XREF(CMcpxVoiceClient_SetLFO, 3911, 12,

    XREF_CMcpxVoiceClient_SetLFO,
    XRefZero)

        { 0x10, 0x8B },
        { 0x21, 0xEB },

        { 0x7D, 0x75 },
        { 0x7E, 0x28 },
        { 0x7F, 0x39 },
        { 0x80, 0x05 },
        { 0x81, 0x10 },
        { 0x82, 0x00 },
        { 0x83, 0x82 },
        { 0x84, 0xFE },

        { 0xA1, 0x89 },
        { 0xB7, 0x6C },
OOVPA_END;

// ******************************************************************
// * CDirectSoundVoice::SetLFO
// ******************************************************************
OOVPA_XREF(CDirectSoundVoice_SetLFO, 3911, 10,

    XREF_CDirectSoundVoice_SetLFO,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CMcpxVoiceClient_SetLFO ),

        { 0x01, 0x57 },
        { 0x0D, 0x8B },
        { 0x0E, 0x44 },
        { 0x0F, 0x24 },
        { 0x10, 0x10 },
        { 0x11, 0x8B },
        { 0x12, 0x48 },
        { 0x2E, 0xC2 },
        { 0x2F, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetLFO
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_SetLFO, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CDirectSoundVoice_SetLFO ),

        { 0x02, 0x24 },
        { 0x06, 0x24 },
        { 0x0A, 0x83 },
        { 0x0E, 0xD9 },
        { 0x12, 0xC8 },
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * CMcpxVoiceClient::SetEG
// ******************************************************************
OOVPA_XREF(CMcpxVoiceClient_SetEG, 3911, 12,

    XREF_CMcpxVoiceClient_SetEG,
    XRefZero)

        { 0x10, 0x8B },
        { 0x21, 0xEB },

        { 0x6B, 0x82 },
        { 0x6C, 0xFE },

        { 0x95, 0x8B },
        { 0x96, 0x96 },
        { 0x97, 0x8C },
        { 0x98, 0x00 },
        { 0x99, 0x00 },
        { 0x9A, 0x00 },
        { 0x9B, 0x89 },
        { 0x9C, 0x15 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundVoice::SetEG
// ******************************************************************
OOVPA_XREF(CDirectSoundVoice_SetEG, 3911, 10,

    XREF_CDirectSoundVoice_SetEG,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CMcpxVoiceClient_SetEG ),

        { 0x01, 0x57 },
        { 0x0D, 0x8B },
        { 0x0E, 0x44 },
        { 0x0F, 0x24 },
        { 0x10, 0x10 },
        { 0x11, 0x8B },
        { 0x12, 0x48 },
        { 0x2E, 0xC2 },
        { 0x2F, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetEG
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_SetEG, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CDirectSoundVoice_SetEG ),

        { 0x02, 0x24 },
        { 0x06, 0x24 },
        { 0x0A, 0x83 },
        { 0x0E, 0xD9 },
        { 0x12, 0xC8 },
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetOutputBuffer
// ******************************************************************
//Generic OOVPA as of 3911 and newer
OOVPA_XREF(IDirectSoundBuffer_SetOutputBuffer, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x15, XREF_CDirectSoundBuffer_SetOutputBuffer ),

        { 0x02, 0x24 },
        { 0x06, 0x24 },
        { 0x0A, 0x83 },
        { 0x0E, 0xD9 },
        { 0x12, 0xC8 },
        { 0x19, 0xC2 },
        { 0x1A, 0x08 },
OOVPA_END;

// ******************************************************************
// * CDirectSoundVoice::SetMixBinVolumes
// ******************************************************************
OOVPA_XREF(CDirectSoundVoice_SetMixBinVolumes, 3911, 8,

    XREF_CDirectSoundVoice_SetMixBinVolumes,
    XRefOne)

        XREF_ENTRY( 0x54, XREF_CMcpxVoiceClient_SetVolume ),

        { 0x0D, 0x65 },
        { 0x1C, 0x53 },
        { 0x2B, 0xC0 },
        { 0x3A, 0xC7 },
        { 0x49, 0xFC },
        { 0x58, 0x83 },
        { 0x67, 0x15 },
OOVPA_END;

// ******************************************************************
// * IDirectSoundBuffer_SetMixBinVolumes_12
// ******************************************************************
OOVPA_XREF(IDirectSoundBuffer_SetMixBinVolumes_12, 3911, 9,

    XRefNoSaveIndex,
    XRefOne)

        XREF_ENTRY( 0x19, XREF_CDirectSoundVoice_SetMixBinVolumes ),

        { 0x02, 0x24 },
        { 0x06, 0x24 },
        { 0x0A, 0xFF },
        { 0x0E, 0x83 },
        { 0x12, 0xD9 },
        { 0x16, 0xC8 },
        { 0x1D, 0xC2 },
        { 0x1E, 0x0C },
OOVPA_END;

// ******************************************************************
// * CDirectSoundStream::SetMixBinVolumes
// ******************************************************************
OOVPA_XREF(CDirectSoundStream_SetMixBinVolumes_12, 3911, 9,

    XREF_CDirectSoundStream_SetMixBinVolumes,
    XRefOne)

        XREF_ENTRY( 0x11, XREF_CDirectSoundVoice_SetMixBinVolumes ),

        { 0x01, 0x74 },
        { 0x04, 0x8B },
        { 0x07, 0x08 },
        { 0x0A, 0x24 },
        { 0x0D, 0xC0 },
        { 0x10, 0xE8 },
        { 0x15, 0xC2 },
        { 0x16, 0x0C },
OOVPA_END;

// ******************************************************************
// * CMcpxAPU_Commit3dSettings
// ******************************************************************
OOVPA_XREF(CMcpxAPU_Commit3dSettings, 3911, 11,

    XREF_CMcpxAPU_Commit3dSettings,
    XRefZero)

        // CMcpxAPU_Commit3dSettings+0x56 : fld dword ptr [eax+0x174]
        { 0x56, 0xD9 },
        { 0x57, 0x80 },
        { 0x58, 0x74 },
        { 0x59, 0x01 },
        { 0x5A, 0x00 },
        { 0x5B, 0x00 },

        // CMcpxAPU_Commit3dSettings+0xA8 : fsubp st(1), st
        { 0xA8, 0xDE },
        { 0xA9, 0xE9 },

        // CMcpxAPU_Commit3dSettings+0xD4 : mov esi, 0x118
        { 0xD4, 0xBE },
        { 0xD5, 0x18 },
        { 0xD6, 0x01 },
OOVPA_END;

// ******************************************************************
// * CDirectSound_CommitDeferredSettings
// ******************************************************************
OOVPA_XREF(CDirectSound_CommitDeferredSettings, 3911, 10,

    XREF_CDirectSound_CommitDeferredSettings,
    XRefOne)

        // CDirectSound_CommitDeferredSettings+0x12 : call [CMcpxAPU_Commit3dSettings]
        XREF_ENTRY( 0x12, XREF_CMcpxAPU_Commit3dSettings ),

        // CDirectSound_CommitDeferredSettings+0x0C : mov ecx, [eax+0x0C]
        { 0x0C, 0x8B },
        { 0x0D, 0x48 },
        { 0x0E, 0x0C },

        // CDirectSound_CommitDeferredSettings+0x0F : push 0
        { 0x0F, 0x6A },
        { 0x10, 0x00 },

        // CDirectSound_CommitDeferredSettings+0x19 : jz +0x0B
        { 0x19, 0x74 },
        { 0x1A, 0x0B },

        // CDirectSound_CommitDeferredSettings+0x28 : retn 0x04
        { 0x28, 0xC2 },
        { 0x29, 0x04 },
OOVPA_END;

// ******************************************************************
// * IDirectSound_CommitDeferredSettings
// ******************************************************************
//Generic OOVPA as of 3911 and newer
OOVPA_XREF(IDirectSound_CommitDeferredSettings, 3911, 8,

    XRefNoSaveIndex,
    XRefOne)

        // IDirectSound_CommitDeferredSettings+0x11 : call [CDirectSound_CommitDeferredSettings]
        XREF_ENTRY( 0x11, XREF_CDirectSound_CommitDeferredSettings ), 

        // IDirectSound_CommitDeferredSettings+0x06 : and eax, 0xFFFFFFF8
        { 0x06, 0x83 },
        { 0x07, 0xC0 },
        { 0x08, 0xF8 },

        // IDirectSound_CommitDeferredSettings+0x09 : neg ecx
        { 0x09, 0xF7 },
        { 0x0A, 0xD9 },

        // IDirectSound_CommitDeferredSettings+0x15 : retn 0x04
        { 0x15, 0xC2 },
        { 0x16, 0x04 },
OOVPA_END;

// ******************************************************************
// * CDirectSound_SetOrientation
// ******************************************************************
OOVPA_XREF(CDirectSound_SetOrientation, 3911, 13,

    XREF_CDirectSound_SetOrientation,
    XRefZero)

        // CDirectSound_SetOrientation+0x00 : push ebp
        { 0x00 , 0x55 },

        { 0x0F , 0x8B },
        { 0x11 , 0x0C },
        { 0x15 , 0x8B },
        { 0x17 , 0x10 },
        { 0x1B , 0x8B },
        { 0x1D , 0x14 },
        { 0x21 , 0x8B },
        { 0x23 , 0x18 },
        { 0x27 , 0x8B },
        { 0x29 , 0x1C },
        { 0x2D , 0x8B },
        { 0x2F , 0x20 },
OOVPA_END;

// ******************************************************************
// * IDirectSound_SetOrientation
// ******************************************************************
//Generic OOVPA as of 3911 and newer
OOVPA_XREF(IDirectSound_SetOrientation, 3911, 15,
    XRefNoSaveIndex,
    XRefOne)

        // IDirectSound_CommitDeferredSettings+0x11 : call [CDirectSound_CommitDeferredSettings]
        XREF_ENTRY( 0x42, XREF_CDirectSound_SetOrientation ), 

        // IDirectSound_SetOrientation+0x00 : push ebp
        { 0x00 , 0x55 },

        // IDirectSound_SetOrientation+0x06 : fld [ebp+0x20]
        { 0x06, 0xD9 },
        { 0x07, 0x45 },
        { 0x08, 0x20 },

        // IDirectSound_SetOrientation+0x0C : sub esp, 0x18
        { 0x0C, 0x83 },
        { 0x0D, 0xEC },
        { 0x0E, 0x18 },

        // IDirectSound_SetOrientation+0x18 : add eax, 0xFFFFFFF8
        { 0x18, 0x83 },
        { 0x19, 0xC0 },
        { 0x1A, 0xF8 },

        // IDirectSound_SetOrientation+0x1F : neg ecx
        { 0x1F, 0xF7 },
        { 0x20, 0xD9 },

        // IDirectSound_SetOrientation+0x47 : retn 0x20
        { 0x47, 0xC2 },
        { 0x48, 0x20 },
OOVPA_END;

// ******************************************************************
// * IDirectSound_AddRef
// ******************************************************************
//Generic OOVPA as of 3911 and newer
OOVPA_NO_XREF(IDirectSound_AddRef, 3911, 12)

        // IDirectSound_AddRef+0x04 : lea ecx, [eax-8]
        { 0x04, 0x8D },
        { 0x05, 0x48 },
        { 0x06, 0xF8 },

        // IDirectSound_AddRef+0x07 : neg eax
        { 0x07, 0xF7 },
        { 0x08, 0xD8 },

        // IDirectSound_AddRef+0x09 : sbb eax, eax
        { 0x09, 0x1B },
        { 0x0A, 0xC0 },

        // IDirectSound_AddRef+0x0D : mov ecx, [eax]
        { 0x0D, 0x8B },
        { 0x0E, 0x08 },

        // IDirectSound_AddRef+0x10 : call dword ptr [ecx+4]
        { 0x10, 0xFF },
        { 0x11, 0x51 },
        { 0x12, 0x04 },
OOVPA_END;

// ******************************************************************
// * IDirectSound_Release
// ******************************************************************
//Generic OOVPA as of 3911 and newer
OOVPA_NO_XREF(IDirectSound_Release, 3911, 10)

        // IDirectSound_Release+0x04 : lea ecx, [eax-8]
        { 0x04, 0x8D },
        { 0x05, 0x48 },
        { 0x06, 0xF8 },

        // IDirectSound_Release+0x07 : neg eax
        { 0x07, 0xF7 },
        { 0x08, 0xD8 },

        // IDirectSound_Release+0x10 : call dword ptr [ecx+8]
        { 0x10, 0xFF },
        { 0x11, 0x51 },
        { 0x12, 0x08 },

        // IDirectSound_Release+0x13 : retn 0x04
        { 0x13, 0xC2 },
        { 0x14, 0x04 },
OOVPA_END;
