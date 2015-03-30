/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2012-2015 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *********************************************************************************/

#include "redgreenprocessor.h"
#include <modules/opengl/textureutils.h>

namespace inviwo {

ProcessorClassIdentifier(RedGreenProcessor, "org.inviwo.RedGreenProcessor");
ProcessorClassVersion(RedGreenProcessor, 0);
ProcessorDisplayName(RedGreenProcessor, "Red Green Processor");
ProcessorTags(RedGreenProcessor, Tags::GL);
ProcessorCategory(RedGreenProcessor, "Various");
ProcessorCodeState(RedGreenProcessor, CODE_STATE_STABLE);

RedGreenProcessor::RedGreenProcessor()
    : Processor(), outportRed_("outportRed"), outportGreen_("outportGreen") {

    addPort(outportRed_);
    addPort(outportGreen_);
}

RedGreenProcessor::~RedGreenProcessor() {}

void RedGreenProcessor::initialize() { Processor::initialize(); }

void RedGreenProcessor::deinitialize() { Processor::deinitialize(); }

void RedGreenProcessor::process() {
    utilgl::activateTarget(outportRed_);
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    utilgl::deactivateCurrentTarget();
    utilgl::activateTarget(outportGreen_);
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    utilgl::deactivateCurrentTarget();
}

}  // namespace
