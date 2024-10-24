/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/EBus/EBus.h>
#include <AzCore/PlatformDef.h>

#include <AzCore/Asset/AssetCommon.h>
#include <AzCore/Asset/AssetManagerBus.h>
#include <AzCore/Asset/AssetTypeInfoBus.h>
#include <AzCore/Component/EntityBus.h>
#include <AzCore/Component/NonUniformScaleBus.h>
#include <AzCore/Component/TickBus.h>
#include <AzCore/Component/TransformBus.h>
#include <AzCore/Debug/TraceMessageBus.h>
#include <AzCore/RTTI/BehaviorContext.h>


#define DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(a) \
namespace AZ \
{ \
   template class AZ_DLL_EXPORT EBus<a, a>; \
   template class AZ_DLL_EXPORT Internal::NonIdHandler<a, a, EBus<a, a>::BusesContainer>; \
}

#define DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(a) \
namespace AZ \
{ \
   template class AZ_DLL_EXPORT EBus<a, a>; \
   template class AZ_DLL_EXPORT Internal::IdHandler<a, a, EBus<a, a>::BusesContainer>; \
   template class AZ_DLL_EXPORT Internal::MultiHandler<a, a, EBus<a, a>::BusesContainer>; \
}

#define DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS_WITH_TRAITS(a, b) \
namespace AZ \
{ \
   template class AZ_DLL_EXPORT EBus<a, b>; \
   template class AZ_DLL_EXPORT Internal::NonIdHandler<a, b, EBus<a, b>::BusesContainer>; \
}

#define DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS_WITH_TRAITS(a, b) \
namespace AZ \
{ \
   template class AZ_DLL_EXPORT EBus<a, b>; \
   template class AZ_DLL_EXPORT Internal::IdHandler<a, b, EBus<a, b>::BusesContainer>; \
   template class AZ_DLL_EXPORT Internal::MultiHandler<a, b, EBus<a, b>::BusesContainer>; \
}


// Asset buses
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(Data::AssetManagerNotifications);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(Data::AssetCatalogRequests);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(Data::AssetManagerEvents);
DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(AssetTypeInfo);
DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(Data::AssetEvents);

// Component buses
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(TickEvents);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(TickRequests);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(SystemTickEvents);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(EntityEvents);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(TransformInterface);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(TransformNotification);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(NonUniformScaleRequests);
DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(TransformHierarchyInformation);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS_WITH_TRAITS(ComponentApplicationRequests, ComponentApplicationRequestsEBusTraits);
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS_WITH_TRAITS(ComponentDescriptor, ComponentDescriptorBusTraits);

// Debug buses
DECLARE_EBUS_INSTANTIATION_DLL_SINGLE_ADDRESS(Debug::TraceMessageEvents);

// RTTI buses
DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(BehaviorContextEvents);
DECLARE_EBUS_INSTANTIATION_DLL_MULTI_ADDRESS(BehaviorObjectSignalsInterface);
