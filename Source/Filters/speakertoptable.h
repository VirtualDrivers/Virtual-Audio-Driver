/*++

Copyright (c) Microsoft Corporation All Rights Reserved

Module Name:

    speakertoptable.h

Abstract:

    Declaration of topology tables.
--*/

#ifndef _VIRTUALAUDIODRIVER_SPEAKERTOPTABLE_H_
#define _VIRTUALAUDIODRIVER_SPEAKERTOPTABLE_H_

#include "endpoints.h"

//=============================================================================
static
KSDATARANGE SpeakerTopoPinDataRangesBridge[] =
{
 {
   sizeof(KSDATARANGE),
   0,
   0,
   0,
   STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
   STATICGUIDOF(KSDATAFORMAT_SUBTYPE_ANALOG),
   STATICGUIDOF(KSDATAFORMAT_SPECIFIER_NONE)
 }
};

//=============================================================================
static
PKSDATARANGE SpeakerTopoPinDataRangePointersBridge[] =
{
  &SpeakerTopoPinDataRangesBridge[0]
};

//=============================================================================
static
PCPIN_DESCRIPTOR SpeakerTopoMiniportPins[] =
{
  // KSPIN_TOPO_WAVEOUT_SOURCE
  {
    0,
    0,
    0,                                                  // InstanceCount
    NULL,                                               // AutomationTable
    {                                                   // KsPinDescriptor
      0,                                                // InterfacesCount
      NULL,                                             // Interfaces
      0,                                                // MediumsCount
      NULL,                                             // Mediums
      SIZEOF_ARRAY(SpeakerTopoPinDataRangePointersBridge),// DataRangesCount
      SpeakerTopoPinDataRangePointersBridge,            // DataRanges
      KSPIN_DATAFLOW_IN,                                // DataFlow
      KSPIN_COMMUNICATION_NONE,                         // Communication
      &KSCATEGORY_AUDIO,                                // Category
      NULL,                                             // Name
      0                                                 // Reserved
    }
  },
  // KSPIN_TOPO_LINEOUT_DEST
  {
    0,
    0,
    0,                                                  // InstanceCount
    NULL,                                               // AutomationTable
    {                                                   // KsPinDescriptor
      0,                                                // InterfacesCount
      NULL,                                             // Interfaces
      0,                                                // MediumsCount
      NULL,                                             // Mediums
      SIZEOF_ARRAY(SpeakerTopoPinDataRangePointersBridge),// DataRangesCount
      SpeakerTopoPinDataRangePointersBridge,            // DataRanges
      KSPIN_DATAFLOW_OUT,                               // DataFlow
      KSPIN_COMMUNICATION_NONE,                         // Communication
      &KSNODETYPE_SPEAKER,                              // Category
      NULL,                                             // Name
      0                                                 // Reserved
    }
  }
};

//=============================================================================
static
KSJACK_DESCRIPTION SpeakerJackDescBridge =
{
    KSAUDIO_SPEAKER_STEREO,
    JACKDESC_RGB(0xB3,0xC9,0x8C),              // Color spec for green
    eConnTypeUnknown,
    eGeoLocFront,
    eGenLocPrimaryBox,
    ePortConnIntegratedDevice,
    TRUE
};

// Only return a KSJACK_DESCRIPTION for the physical bridge pin.
static 
PKSJACK_DESCRIPTION SpeakerJackDescriptions[] =
{
    NULL,
    &SpeakerJackDescBridge
};

//=============================================================================
static
PCPROPERTY_ITEM SpeakerPropertiesVolume[] =
{
    {
    &KSPROPSETID_Audio,
    KSPROPERTY_AUDIO_VOLUMELEVEL,
    KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
    PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerVolume, SpeakerPropertiesVolume);

//=============================================================================
static
PCPROPERTY_ITEM SpeakerPropertiesMute[] =
{
  {
    &KSPROPSETID_Audio,
    KSPROPERTY_AUDIO_MUTE,
    KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
    PropertyHandler_SpeakerTopology
  }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerMute, SpeakerPropertiesMute);

//=============================================================================
// Tone Control (Bass/Treble)
//=============================================================================
static
PCPROPERTY_ITEM SpeakerPropertiesBass[] =
{
    {
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_DEV_SPECIFIC,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerBass, SpeakerPropertiesBass);

static
PCPROPERTY_ITEM SpeakerPropertiesTreble[] =
{
    {
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_DEV_SPECIFIC,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerTreble, SpeakerPropertiesTreble);

//=============================================================================
// Audio Effects (Reverb/Chorus)
//=============================================================================
static
PCPROPERTY_ITEM SpeakerPropertiesReverb[] =
{
    {
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_DEV_SPECIFIC,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerReverb, SpeakerPropertiesReverb);

static
PCPROPERTY_ITEM SpeakerPropertiesChorus[] =
{
    {
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_DEV_SPECIFIC,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerChorus, SpeakerPropertiesChorus);

//=============================================================================
// Acoustic Echo Cancellation
//=============================================================================
static
PCPROPERTY_ITEM SpeakerPropertiesAec[] =
{
    {
        &KSPROPSETID_Audio,
        KSPROPERTY_AUDIO_DEV_SPECIFIC,
        KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopology
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerAec, SpeakerPropertiesAec);

//=============================================================================
static
PCNODE_DESCRIPTOR SpeakerTopologyNodes[] =
{
    // KSNODE_TOPO_SPEAKER_VOLUME
    {
      0,                              // Flags
      &AutomationSpeakerVolume,     // AutomationTable
      &KSNODETYPE_VOLUME,             // Type
      &KSAUDFNAME_MASTER_VOLUME         // Name
    },
    // KSNODE_TOPO_SPEAKER_MUTE
    {
      0,                              // Flags
      &AutomationSpeakerMute,       // AutomationTable
      &KSNODETYPE_MUTE,               // Type
      &KSAUDFNAME_MASTER_MUTE            // Name
    },
    // KSNODE_TOPO_BASS
    {
      0,                              // Flags
      &AutomationSpeakerBass,       // AutomationTable
      &KSNODETYPE_TONE,               // Type
      &KSAUDFNAME_BASS                    // Name
    },
    // KSNODE_TOPO_TREBLE
    {
      0,                              // Flags
      &AutomationSpeakerTreble,     // AutomationTable
      &KSNODETYPE_TONE,               // Type
      &KSAUDFNAME_TREBLE                  // Name
    },
    // KSNODE_TOPO_REVERB
    {
      0,                              // Flags
      &AutomationSpeakerReverb,     // AutomationTable
      &KSNODETYPE_REVERB,             // Type
      NULL                            // Name
    },
    // KSNODE_TOPO_CHORUS
    {
      0,                              // Flags
      &AutomationSpeakerChorus,     // AutomationTable
      &KSNODETYPE_CHORUS,             // Type
      NULL                            // Name
    },
    // KSNODE_TOPO_AEC
    {
      0,                              // Flags
      &AutomationSpeakerAec,        // AutomationTable
      &KSNODETYPE_ACOUSTIC_ECHO_CANCEL, // Type
      NULL                            // Name
    }
};

C_ASSERT(KSNODE_TOPO_SPEAKER_VOLUME == 0);
C_ASSERT(KSNODE_TOPO_SPEAKER_MUTE == 1);
C_ASSERT(KSNODE_TOPO_BASS == 2);
C_ASSERT(KSNODE_TOPO_TREBLE == 3);
C_ASSERT(KSNODE_TOPO_REVERB == 4);
C_ASSERT(KSNODE_TOPO_CHORUS == 5);
C_ASSERT(KSNODE_TOPO_AEC == 6);

static
PCCONNECTION_DESCRIPTOR SpeakerTopoMiniportConnections[] =
{
    //  FromNode,                 FromPin,                    ToNode,                 ToPin
    {   PCFILTER_NODE,            KSPIN_TOPO_WAVEOUT_SOURCE,    KSNODE_TOPO_SPEAKER_VOLUME,     1 },
    {   KSNODE_TOPO_SPEAKER_VOLUME,       0,                          KSNODE_TOPO_BASS,       1 },
    {   KSNODE_TOPO_BASS,         0,                          KSNODE_TOPO_TREBLE,     1 },
    {   KSNODE_TOPO_TREBLE,       0,                          KSNODE_TOPO_REVERB,     1 },
    {   KSNODE_TOPO_REVERB,       0,                          KSNODE_TOPO_CHORUS,     1 },
    {   KSNODE_TOPO_CHORUS,       0,                          KSNODE_TOPO_SPEAKER_MUTE,       1 },
    {   KSNODE_TOPO_SPEAKER_MUTE,         0,                          PCFILTER_NODE,          KSPIN_TOPO_LINEOUT_DEST }
};

//=============================================================================
static
PCPROPERTY_ITEM PropertiesSpeakerTopoFilter[] =
{
    {
        &KSPROPSETID_Jack,
        KSPROPERTY_JACK_DESCRIPTION,
        KSPROPERTY_TYPE_GET |
        KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopoFilter
    },
    {
        &KSPROPSETID_Jack,
        KSPROPERTY_JACK_DESCRIPTION2,
        KSPROPERTY_TYPE_GET |
        KSPROPERTY_TYPE_BASICSUPPORT,
        PropertyHandler_SpeakerTopoFilter
    }
};

DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerTopoFilter, PropertiesSpeakerTopoFilter);

//=============================================================================
static
PCFILTER_DESCRIPTOR SpeakerTopoMiniportFilterDescriptor =
{
  0,                                            // Version
  &AutomationSpeakerTopoFilter,                 // AutomationTable
  sizeof(PCPIN_DESCRIPTOR),                     // PinSize
  SIZEOF_ARRAY(SpeakerTopoMiniportPins),        // PinCount
  SpeakerTopoMiniportPins,                      // Pins
  sizeof(PCNODE_DESCRIPTOR),                    // NodeSize
  SIZEOF_ARRAY(SpeakerTopologyNodes),           // NodeCount
  SpeakerTopologyNodes,                         // Nodes
  SIZEOF_ARRAY(SpeakerTopoMiniportConnections), // ConnectionCount
  SpeakerTopoMiniportConnections,               // Connections
  0,                                            // CategoryCount
  NULL                                          // Categories
};

#endif // _VIRTUALAUDIODRIVER_SPEAKERTOPTABLE_H_
