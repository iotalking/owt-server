/*
 * Copyright 2015 Intel Corporation All Rights Reserved. 
 * 
 * The source code contained or described herein and all documents related to the 
 * source code ("Material") are owned by Intel Corporation or its suppliers or 
 * licensors. Title to the Material remains with Intel Corporation or its suppliers 
 * and licensors. The Material contains trade secrets and proprietary and 
 * confidential information of Intel or its suppliers and licensors. The Material 
 * is protected by worldwide copyright and trade secret laws and treaty provisions. 
 * No part of the Material may be used, copied, reproduced, modified, published, 
 * uploaded, posted, transmitted, distributed, or disclosed in any way without 
 * Intel's prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual 
 * property right is granted to or conferred upon you by disclosure or delivery of 
 * the Materials, either expressly, by implication, inducement, estoppel or 
 * otherwise. Any license under such intellectual property rights must be express 
 * and approved by Intel in writing.
 */

#ifndef ExternalOutput_h
#define ExternalOutput_h

#include "AudioExternalOutput.h"
#include "MediaRecorder.h"
#include "VideoExternalOutput.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/shared_ptr.hpp>
#include <logger.h>

namespace mcu {

// The ExternalOutput class can also be exposed to Node addon, just like the mcu::Mixer
class ExternalOutput : public erizo::MediaSink {
    DECLARE_LOGGER();

public:
    ExternalOutput(boost::property_tree::ptree& outputConfig);
    virtual ~ExternalOutput();

    // Implements the MediaSink interfaces.
    // TODO: This is hard coded!
    int preferredAudioPayloadType() { return PCMU_8000_PT; }
    int preferredVideoPayloadType() { return VP8_90000_PT; }

    int deliverAudioData(char* buf, int len);
    int deliverVideoData(char* buf, int len);

private:
    boost::shared_ptr<VideoExternalOutput> m_videoExternalOutput;
    boost::shared_ptr<AudioExternalOutput> m_audioExternalOutput;
    boost::shared_ptr<MediaRecorder> m_recorder;
};

} /* namespace mcu */

#endif /* ExternalOutput_h */