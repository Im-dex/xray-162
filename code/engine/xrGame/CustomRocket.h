//////////////////////////////////////////////////////////////////////
// CustomRocket.h:	������, ������� �������� RocketLauncher 
//					(����� ������, ��������� � ���������� ��������)
//////////////////////////////////////////////////////////////////////

#pragma once

#include "physic_item.h"
#include "../xrphysics/PHUpdateObject.h"

class CRocketLauncher;
struct dContact;
struct SGameMtl;
struct SRoketContact
{
	bool contact;
	Fvector pos;
	Fvector up;
	SRoketContact()
	{
		contact = false;
	}
};

class CCustomRocket : public CPhysicItem,
					  public CPHUpdateObject
{
private:
	typedef CPhysicItem inherited;
	friend CRocketLauncher;
public:
	//////////////////////////////////////////////////////////////////////////
	//	Generic
	//////////////////////////////////////////////////////////////////////////

	CCustomRocket(void);
	virtual ~CCustomRocket(void);

	virtual void Load(LPCSTR section);
	virtual BOOL net_Spawn(CSE_Abstract* DC);
	virtual void net_Destroy();
	virtual BOOL						AlwaysTheCrow				()				{ return TRUE; }

	virtual void reinit		();
	virtual void reload		(LPCSTR section);

	virtual void OnH_A_Independent	();
	virtual void OnH_B_Independent	(bool just_before_destroy);
	virtual void OnH_B_Chield		();
	virtual void OnH_A_Chield		();
	virtual void UpdateCL();

	virtual BOOL UsedAI_Locations	()			{return	(FALSE);}
	virtual bool Useful				() const	{return (m_eState == eInactive);	}

	virtual void renderable_Render() {inherited::renderable_Render();}

	//�������� ���������� ��������
	virtual void			activate_physic_shell	();
	virtual void			create_physic_shell		();

	virtual void			PhDataUpdate			(float step);
	virtual void			PhTune					(float step);

	//////////////////////////////////////////////////////////////////////////
	//	Rocket Properties
	//////////////////////////////////////////////////////////////////////////
public:
#ifdef DEBUG
	CGameObject*			owner					(){return m_pOwner;}
#endif
	virtual	void			StartEngine				();
	virtual	void			StopEngine				();
	virtual	void			UpdateEngine			();
	virtual	void			UpdateEnginePh			();

	virtual	void			StartFlying				();
	virtual	void			StopFlying				();

	virtual	void			SetLaunchParams			(const Fmatrix& xform, 
													 const Fvector& vel,
													 const Fvector& angular_vel);

	virtual void			OnEvent					(NET_Packet& P, u16 type);
	bool					m_bLaunched;
protected:
	//��������� �� ��������� RocketLauncher - ������� �������� ������
	CGameObject*			m_pOwner;

	SRoketContact			m_contact;
	//��������� ������� �������� RocketLauncher-�� ����� ������
	Fmatrix					m_LaunchXForm;
	Fvector					m_vLaunchVelocity;
	Fvector					m_vLaunchAngularVelocity;

	enum ERocketState{
		eInactive,		//������ ��������� � ���������� � ���������
		eEngine,		//������� ���������
		eFlying,		//������ �����
		eCollide		//��������� ������������ � ������������
	};

	//������� ��������� ������
	ERocketState m_eState;

	//��������� ������������
	bool		m_bEnginePresent;
	//����� ������ ��������� � ������� ������
	int			m_dwEngineWorkTime;
	//���� ������ ��������� (������ �������� � �������)
	float		m_fEngineImpulse;
	float		m_fEngineImpulseUp;
	//������� ����� ������ ���������
	int			m_dwEngineTime;

	//��������� ������������
	virtual void			Contact(const Fvector &pos, const Fvector &normal);
			void			PlayContact();
	static	void			ObjectContactCallback(bool& do_colide,bool bo1,dContact& c,SGameMtl * /*material_1*/,SGameMtl * /*material_2*/);


	//////////////////////////////////////////////////////////////////////////
	//	Lights
	//////////////////////////////////////////////////////////////////////////
protected:
	//����, ��� ��������� ����� ���� ��������
	bool			m_bLightsEnabled;
	//����, ��� ��������� ����� �����������
	//������ � ����������
	bool			m_bStopLightsWithEngine;
	//��������� �� ����� ������ � ������ ���������
	ref_light		m_pTrailLight;
	Fcolor			m_TrailLightColor;
	float			m_fTrailLightRange;
	ref_sound		m_flyingSound;

protected:
	virtual void	StartLights();
	virtual void	StopLights();
	virtual void	UpdateLights();
    
	
	//////////////////////////////////////////////////////////////////////////
	//	Particles
	//////////////////////////////////////////////////////////////////////////
protected:	
	//��� ��������� ���������
	shared_str			m_sEngineParticles;
	CParticlesObject*	m_pEngineParticles;
	//��� ��������� ������
	shared_str			m_sFlyParticles;
	CParticlesObject*	m_pFlyParticles;

	Fvector				m_vPrevVel;
	float				m_time_to_explode;
#ifdef	DEBUG
	float				gbg_rocket_speed1;
	float				gbg_rocket_speed2;
#endif
protected:
	virtual void		StartEngineParticles();
	virtual void		StopEngineParticles();
	virtual void		StartFlyParticles();
	virtual void		StopFlyParticles();

	virtual void		UpdateParticles();
#ifdef DEBUG
	virtual void		deactivate_physics_shell ();
#endif
};