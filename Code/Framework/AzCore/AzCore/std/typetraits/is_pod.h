/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <AzCore/std/typetraits/config.h>

namespace AZStd
{
    AZ_PUSH_DISABLE_WARNING(4996, "-Wunknown-warning-option")
    using std::is_pod;
    AZ_POP_DISABLE_WARNING
    //template<typename t>
    //class is_pod
}
