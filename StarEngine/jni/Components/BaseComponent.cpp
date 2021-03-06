#include "BaseComponent.h"
#include "../Objects/Object.h"
#include "../Context.h"
#include "../Logger.h"

namespace star
{
	BaseComponent::BaseComponent():
		m_pParentObject(nullptr),
		m_bInitialized(false),
		m_bIsEnabled(true)
	{
	}

	BaseComponent::BaseComponent(Object* parent):
		m_pParentObject(parent),
		m_bInitialized(false),
		m_bIsEnabled(true)
	{
	}

	BaseComponent::~BaseComponent(void)
	{
	}

	void BaseComponent::Initialize()
	{
		if(m_bInitialized)
		{
#ifdef _DEBUG
			Logger::GetInstance()->Log(LogLevel::Warning, _T("Component Already Initialized!"));
#endif
			return;
		}
		InitializeComponent();
		m_bInitialized = true;
	}

	void BaseComponent::BaseUpdate(const Context& context)
	{
		if(!m_bIsEnabled)
		{
			return;
		}
		Update(context);
	}

	void BaseComponent::BaseDraw()
	{
		if(!m_bIsEnabled)
		{
			return;
		}
		Draw();
	}
	
	bool BaseComponent::IsInitialized() const
	{
		return m_bInitialized;
	}

	Object* BaseComponent::GetParent() const
	{
		return m_pParentObject;
	}
	
	void BaseComponent::SetParent(Object* parent)
	{
		m_pParentObject = parent;
	}

	BaseScene* BaseComponent::GetGameScene() const
	{ 
		return m_pParentObject->GetScene();
	}

	TransformComponent* BaseComponent::GetTransform() const
	{
		 return m_pParentObject->GetComponent<TransformComponent>();
	}

	void BaseComponent::SetEnabled(bool bEnabled)
	{
		m_bIsEnabled = bEnabled;
	}

	bool BaseComponent::IsEnabled() const
	{
		return m_bIsEnabled;
	}
}
