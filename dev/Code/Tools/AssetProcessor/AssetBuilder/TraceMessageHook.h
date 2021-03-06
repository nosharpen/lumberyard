/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

#include <AzCore/Debug/TraceMessageBus.h>
#include <AzCore/std/string/osstring.h>

class TraceMessageHook
    : public AZ::Debug::TraceMessageBus::Handler
{
public:
    TraceMessageHook();
    ~TraceMessageHook() override;
    
    bool OnAssert(const char* message) override;
    bool OnError(const char* /*window*/, const char* message) override;
    bool OnWarning(const char* /*window*/, const char* message) override;
    bool OnException(const char* message) override;
    bool OnOutput(const char* window, const char* message) override;

    static void CleanMessage(FILE* stream, const char* prefix, const char* rawMessage);

    // once we're in an exception, we accept all log data as error, since we will terminate
    // this ensures that call stack info (which is 'traced', not 'exceptioned') is present.
    bool m_isInException = false;
};