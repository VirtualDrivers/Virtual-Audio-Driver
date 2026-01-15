/*++

Copyright (c) Microsoft Corporation All Rights Reserved

Module Name:

    hw.h

Abstract:

    Declaration of Simple Audio Sample HW class. 
    Simple Audio Sample HW has an array for storing mixer and volume settings
    for the topology.
--*/

#ifndef _VIRTUALAUDIODRIVER_HW_H_
#define _VIRTUALAUDIODRIVER_HW_H_

//=============================================================================
// Defines
//=============================================================================
// BUGBUG we should dynamically allocate this...
#define MAX_TOPOLOGY_NODES      20
#define MAX_EQUALIZER_BANDS     10    // 10-band equalizer

//=============================================================================
// Classes
//=============================================================================
///////////////////////////////////////////////////////////////////////////////
// CVirtualAudioDriverHW
// This class represents virtual Simple Audio Sample HW. An array representing volume
// registers and mute registers.

class CVirtualAudioDriverHW
{
public:
protected:
    BOOL                        m_MuteControls[MAX_TOPOLOGY_NODES];
    LONG                        m_VolumeControls[MAX_TOPOLOGY_NODES];
    LONG                        m_PeakMeterControls[MAX_TOPOLOGY_NODES];
    ULONG                       m_ulMux;            // Mux selection
    BOOL                        m_bDevSpecific;
    INT                         m_iDevSpecific;
    UINT                        m_uiDevSpecific;
    // Tone Control (Bass/Treble)
    LONG                        m_BassControls[MAX_TOPOLOGY_NODES];
    LONG                        m_TrebleControls[MAX_TOPOLOGY_NODES];
    // Audio Effects
    LONG                        m_ReverbControls[MAX_TOPOLOGY_NODES];      // Reverb level
    LONG                        m_ChorusControls[MAX_TOPOLOGY_NODES];     // Chorus level
    // Acoustic Echo Cancellation
    BOOL                        m_AecEnabled[MAX_TOPOLOGY_NODES];         // AEC enable/disable
    // Equalizer (multi-band)
    LONG                        m_EqualizerBands[MAX_TOPOLOGY_NODES][MAX_EQUALIZER_BANDS];  // EQ band levels per node
    // Noise Suppression
    BOOL                        m_NoiseSuppressionEnabled[MAX_TOPOLOGY_NODES];  // Noise suppression enable/disable
    LONG                        m_NoiseSuppressionLevel[MAX_TOPOLOGY_NODES];     // Noise suppression strength
    // Automatic Gain Control
    BOOL                        m_AgcEnabled[MAX_TOPOLOGY_NODES];          // AGC enable/disable
    LONG                        m_AgcLevel[MAX_TOPOLOGY_NODES];            // AGC target level

private:

public:
    CVirtualAudioDriverHW();
    
    void                        MixerReset();
    BOOL                        bGetDevSpecific();
    void                        bSetDevSpecific
    (
        _In_  BOOL                bDevSpecific
    );
    INT                         iGetDevSpecific();
    void                        iSetDevSpecific
    (
        _In_  INT                 iDevSpecific
    );
    UINT                        uiGetDevSpecific();
    void                        uiSetDevSpecific
    (
        _In_  UINT                uiDevSpecific
    );
    BOOL                        GetMixerMute
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerMute
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  BOOL                fMute
    );
    ULONG                       GetMixerMux();
    void                        SetMixerMux
    (
        _In_  ULONG               ulNode
    );
    LONG                        GetMixerVolume
    (   
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerVolume
    (   
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  LONG                lVolume
    );
    
    LONG                        GetMixerPeakMeter
    (   
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );

    // Tone Control (Bass/Treble)
    LONG                        GetMixerBass
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerBass
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  LONG                lBass
    );
    LONG                        GetMixerTreble
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerTreble
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  LONG                lTreble
    );

    // Audio Effects
    LONG                        GetMixerReverb
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerReverb
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  LONG                lReverb
    );
    LONG                        GetMixerChorus
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel
    );
    void                        SetMixerChorus
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulChannel,
        _In_  LONG                lChorus
    );

    // Acoustic Echo Cancellation
    BOOL                        GetAecEnabled
    (
        _In_  ULONG               ulNode
    );
    void                        SetAecEnabled
    (
        _In_  ULONG               ulNode,
        _In_  BOOL                fEnabled
    );

    // Equalizer (multi-band)
    LONG                        GetEqualizerBand
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulBand
    );
    void                        SetEqualizerBand
    (
        _In_  ULONG               ulNode,
        _In_  ULONG               ulBand,
        _In_  LONG                lLevel
    );

    // Noise Suppression
    BOOL                        GetNoiseSuppressionEnabled
    (
        _In_  ULONG               ulNode
    );
    void                        SetNoiseSuppressionEnabled
    (
        _In_  ULONG               ulNode,
        _In_  BOOL                fEnabled
    );
    LONG                        GetNoiseSuppressionLevel
    (
        _In_  ULONG               ulNode
    );
    void                        SetNoiseSuppressionLevel
    (
        _In_  ULONG               ulNode,
        _In_  LONG                lLevel
    );

    // Automatic Gain Control
    BOOL                        GetAgcEnabled
    (
        _In_  ULONG               ulNode
    );
    void                        SetAgcEnabled
    (
        _In_  ULONG               ulNode,
        _In_  BOOL                fEnabled
    );
    LONG                        GetAgcLevel
    (
        _In_  ULONG               ulNode
    );
    void                        SetAgcLevel
    (
        _In_  ULONG               ulNode,
        _In_  LONG                lLevel
    );

protected:
private:
};
typedef CVirtualAudioDriverHW    *PCVirtualAudioDriverHW;

#endif  // _VIRTUALAUDIODRIVER_HW_H_
