#pragma once

#include "Engine/Animation/Graph/Animation_RuntimeGraph_Instance.h"
#include "EngineTools/Core/VisualGraph/VisualGraph_UserContext.h"
#include "EngineTools/Core/Helpers/CategoryTree.h"
#include "System/Types/HashMap.h"

//-------------------------------------------------------------------------

namespace EE::TypeSystem { class TypeInfo; }

//-------------------------------------------------------------------------

namespace EE::Animation
{
    class VariationHierarchy;

    namespace GraphNodes
    {
        class ControlParameterToolsNode;
        class VirtualParameterToolsNode;
    }

    //-------------------------------------------------------------------------

    struct ToolsGraphUserContext : public VisualGraph::UserContext
    {
        // Node Helpers
        //-------------------------------------------------------------------------

        inline TInlineVector<GraphNodes::ControlParameterToolsNode*, 20> const& GetControlParameters() const { EE_ASSERT( m_pControlParameters != nullptr ); return *m_pControlParameters; }
        inline TInlineVector<GraphNodes::VirtualParameterToolsNode*, 20> const& GetVirtualParameters() const { EE_ASSERT( m_pVirtualParameters != nullptr ); return *m_pVirtualParameters; }
        inline Category<TypeSystem::TypeInfo const*> const& GetCategorizedNodeTypes() const { return *m_pCategorizedNodeTypes; }

        // Resource Helpers
        //-------------------------------------------------------------------------

        void RequestOpenResource( ResourceID const& resourceID );
        inline TEventHandle<ResourceID const&> OnRequestOpenResource() { return m_onRequestOpenResource; }

        // Debug Data
        //-------------------------------------------------------------------------

        inline bool HasDebugData() const
        {
            return m_pGraphInstance != nullptr && m_pGraphInstance->IsInitialized();
        }

        inline int16_t GetRuntimeGraphNodeIndex( UUID const& nodeID ) const
        {
            auto const foundIter = m_nodeIDtoIndexMap.find( nodeID );
            if ( foundIter != m_nodeIDtoIndexMap.end() )
            {
                return foundIter->second;
            }
            return InvalidIndex;
        }

        bool IsNodeActive( int16_t nodeIdx ) const;

        #if EE_DEVELOPMENT_TOOLS
        PoseNodeDebugInfo GetPoseNodeDebugInfo( int16_t runtimeNodeIdx ) const;
        #endif

        template<typename T>
        inline T GetRuntimeNodeDebugValue( int16_t runtimeNodeIdx ) const
        {
            return m_pGraphInstance->GetRuntimeNodeDebugValue<T>( runtimeNodeIdx );
        }

    public:

        StringID                                                            m_selectedVariationID;
        VariationHierarchy const*                                           m_pVariationHierarchy = nullptr;
        GraphInstance*                                                      m_pGraphInstance = nullptr;
        THashMap<UUID, int16_t>                                             m_nodeIDtoIndexMap;
        TInlineVector<GraphNodes::ControlParameterToolsNode*, 20> const*    m_pControlParameters = nullptr;
        TInlineVector<GraphNodes::VirtualParameterToolsNode*, 20> const*    m_pVirtualParameters = nullptr;
        Category<TypeSystem::TypeInfo const*> const*                        m_pCategorizedNodeTypes = nullptr;
        TypeSystem::TypeRegistry const*                                     m_pTypeRegistry = nullptr;

    private:

        TEvent<ResourceID const&>                                           m_onRequestOpenResource;
    };
}