/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

namespace AZStd
{
    // This class can be used as a base class if a class should not be copyable or copy-assignable
    class noncopyable
    {
    public:
        noncopyable() = default;

        // Delete copy constructor and copy assignment operator
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
    };
} // namespace AZStd
