#include	"stdafx.h"

#include	"death_anims.h"

#include	"actor.h"
#include	"ai/stalker/ai_stalker.h"
#include	"stalker_movement_manager_smart_cover.h"
#include	"weaponshotgun.h"
#include	"explosive.h"
#include	"weaponmagazined.h"
#include	"CharacterPhysicsSupport.h"
#include	"animation_utils.h"
#ifdef	DEBUG
extern xr_token motion_dirs[];
#endif

Fvector& global_hit_position( Fvector &gp, CEntityAlive& ea, const SHit& H )
{
	VERIFY( ea.Visual() );
	IKinematics	*K = ea.Visual( )->dcast_PKinematics( );
	VERIFY( K );
	K->LL_GetTransform( H.bone() ).transform_tiny( gp, H.bone_space_position( ) );
	ea.XFORM().transform_tiny( gp );
	return gp;
}

type_motion::edirection	type_motion::dir( CEntityAlive& ea, const SHit& H, float& angle  )
{
	
	Fvector dir = H.direction();
	dir.y = 0;
	float m = dir.magnitude();
	if( fis_zero( m ) )
	{
		edirection dr;
		dr = (edirection) ::Random.randI( 0, (s32) not_definite );
		VERIFY( dr < not_definite );
		return	dr;
	}
	dir.mul( 1.f / m );

	Fvector z_dir = { ea.XFORM().k.x, 0.f, ea.XFORM().k.z };
	Fvector x_dir =  { ea.XFORM().i.x, 0.f, ea.XFORM().i.z };
	z_dir.normalize_safe();x_dir.normalize_safe();

	float front_factor	= dir.dotproduct( z_dir );
	float sidefactor	= dir.dotproduct( x_dir );

	if( _abs( front_factor ) > M_SQRT1_2 )
	{
		float sign = front_factor < 0.f ? -1.f : 1.f;

		angle = atan2( -sign * sidefactor, sign * front_factor );	

		return sign < 0.f ? front : back;
	} 
	else
	{
		float sign = sidefactor > 0.f ? 1.f : -1.f;

		angle = atan2( sign * front_factor, sign * sidefactor );	
		return sign > 0.f ? left : right;
	}

}

bool is_bone_head( IKinematics &K, u16 bone )
{
	
	const u16 head_bone = K.LL_BoneID( "bip01_head" ) ;
	const u16 neck_bone = K.LL_BoneID( "bip01_neck" ) ;
	return ( bone != BI_NONE ) && 
			neck_bone == bone ||
			find_in_parents( head_bone, bone, K );

}

void type_motion_diagnostic( LPCSTR message, type_motion::edirection dr, const CEntityAlive& ea, const SHit& H, const MotionID &m )
{
#ifdef DEBUG

	if(! death_anim_debug )
		return;
	
	IKinematicsAnimated *KA = smart_cast<IKinematicsAnimated*>( ea.Visual() );
	VERIFY( KA );
	IKinematics *K  = smart_cast<IKinematics*>( ea.Visual() );
	LPCSTR bone_name = "not_definite";
	if( H.bone() != BI_NONE )
	{
		CBoneData& bd = K->LL_GetData( H.bone() );
		bone_name = bd.name.c_str();
	}
	LPCSTR motion_name = "not_set";
	if( m.valid() )
		motion_name = KA->LL_MotionDefName_dbg( m ).first;

	Msg( "death anims: %s, dir: %s, motion: %s,  obj: %s, model: %s, bone: %s " ,message ,motion_dirs[ dr ].name, motion_name, ea.cName().c_str(), ea.cNameVisual().c_str(), bone_name );

#endif
}


 //1.	����������� �������� ������ �� ��������� � ������ 
class	type_motion0: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle )	const
	{
		m = MotionID();
		if( H.initiator() !=  Level().CurrentControlEntity())
			return false;
		
		VERIFY( ea.Visual( ) );
		IKinematics *K = ea.Visual()->dcast_PKinematics();
		VERIFY( K );
		if( !is_bone_head( *K, H.bone() ))
			return false;

		//CAI_Stalker* s = ea.cast_stalker	();
		CCharacterPhysicsSupport* chs = ea.character_physics_support();
		if( !chs || chs->Type( ) == CCharacterPhysicsSupport::etBitting )
			return false;

		VERIFY( chs->movement() );
		
		const Fvector stalker_velocity = chs->movement()->GetVelocity();
		const float stalker_speed = stalker_velocity.magnitude();
		const float min_stalker_speed = 3.65f;
		if(stalker_speed < min_stalker_speed )
			return false;

		const Fvector stalker_velocity_dir = Fvector().mul( stalker_velocity, 1.f/stalker_speed );

		const Fvector dir_to_actor = Fvector().sub( H.initiator()->Position(), ea.Position() ).normalize_safe();

		const float front_angle_cos = _cos( deg2rad ( 20.f ) );
		
		if( stalker_velocity_dir.dotproduct(dir_to_actor) < front_angle_cos )
			return false;

		if( type_motion::front != type_motion::dir( ea, H, angle )  )
			return false;
		Fvector p;
		if( Fvector().sub( H.initiator()->Position(), global_hit_position( p, ea, H ) ).magnitude() > 30.f )
			return false;

		m = motion( front );
		type_motion_diagnostic( " type_motion0: 1. = ����������� �������� ������ �� ��������� � ������ ", front, ea, H, m );
		return true;
	}
};

//2.	���������� ������
class	type_motion1: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const	
	{
		m = MotionID();
//#ifdef DEBUG		
//		if( death_anim_debug )
//			Msg( " type_motion1: 2.	���������� ������  " );
//#endif
		return false;
	}
};

//3.	������ 
class	type_motion2: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const	
	{
		m = MotionID();
		if( H.initiator() !=  Level().CurrentControlEntity())
		return false;
		
		CObject* O = Level().Objects.net_Find( H.weaponID );
		if(!O)
			return false;
		//static_cast<CGameObject*>(O)->cast_weapon()
		CWeaponShotgun* s = smart_cast< CWeaponShotgun* >( static_cast<CGameObject*>(O) );
		if(!s)
			return false;
		Fvector p;
		const	float max_distance = 20.f;
		if(Fvector().sub(H.initiator()->Position(),global_hit_position( p, ea, H )).magnitude() > max_distance)
			return false;
		edirection dr = dir( ea, H, angle );
		m = motion( dr );
		type_motion_diagnostic( " type_motion2: 3.	������ ", dr, ea, H, m );
		return true;
	}
};

//4.	������ (�� �����������), ����� 5 (4) 
class	type_motion3: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const
	{
		m = MotionID();
		if( H.initiator() !=  Level().CurrentControlEntity())
			return false;
		VERIFY( ea.Visual( ) );
		IKinematics *K = ea.Visual()->dcast_PKinematics();
		VERIFY( K );
		if( is_bone_head( *K, H.bone() ) )
		{
			edirection dr = dir( ea, H, angle );
			m = motion( dr );
			type_motion_diagnostic( " type_motion3: 4.	������ (�� �����������), ����� 5 (4)", dr, ea, H, m );
			return true;
		}
		return false;
	}
};

bool is_snipper( u16 weaponID )
{
	CObject* O = Level().Objects.net_Find( weaponID );
	if(!O)
		return false;
	CWeaponMagazined* WM = smart_cast<CWeaponMagazined*>( O );
	if(!WM )
		return false;
	if( !WM->IsZoomed() )
		return false;
	//if( !WM->SingleShotMode() )
		//return false;
	if( !WM->IsScopeAttached() )
		return false;
	
	return true;
}

//5.	��������� � ������. 
class	type_motion4: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const	
	{
		if( H.initiator() !=  Level().CurrentControlEntity())
			return false;
		m = MotionID();
		VERIFY( ea.Visual( ) );
		IKinematics *K = ea.Visual()->dcast_PKinematics();
		VERIFY( K );
		if( !is_bone_head( *K, H.bone() ) )
			return false;

		if( is_snipper( H.weaponID ) )
		{
			edirection dr = dir( ea, H, angle );
			m = motion( dr );
			type_motion_diagnostic( " type_motion4: 5.	��������� � ������", dr, ea, H, m );
			return true;
		}
		return false;
	}
};

//6.	��������� � ����. 
class	type_motion5: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const	
	{
		if( H.initiator() !=  Level().CurrentControlEntity())
			return false;
		m = MotionID();
		VERIFY( ea.Visual( ) );
		IKinematics *K = ea.Visual()->dcast_PKinematics();
		VERIFY( K );

		if(is_snipper( H.weaponID ) && !is_bone_head( *K, H.bone() ))
		{
			edirection dr = dir( ea, H, angle );
			m = motion( dr );
			type_motion_diagnostic( "type_motion5: 6.	��������� � ����", dr, ea, H, m );
			return true;
		}
		return false;
	}
};

//7.	������ 
class	type_motion6: public type_motion
{
	bool predicate( CEntityAlive& ea, const SHit& H, MotionID &m, float &angle ) const	
	{
		
		if( H.initiator() !=  Level().CurrentControlEntity())
			return false;

		if(H.type() == ALife::eHitTypeExplosion)
		{
			edirection dr = dir( ea, H, angle );
			m = motion( dr );
			type_motion_diagnostic( "type_motion6: 7. ������", dr, ea, H, m );
			return true;
		}

		CObject* O = Level().Objects.net_Find( H.weaponID );
		if(!O)
		{
			m = MotionID();
			return false;
		}

		if( smart_cast<CExplosive*>( O ) != 0 )
		{	
			edirection dr = dir( ea, H, angle );
			m = motion(  dr );
			type_motion_diagnostic( "type_motion6: 7. ������ - �������", dr, ea, H, m );
			return true;
		}

		return false;
	}
};

void death_anims::setup		( IKinematicsAnimated* k, LPCSTR section, CInifile const * ini )
{
	clear();
//	if( !ini )
//			return;
	VERIFY( k );
	VERIFY( section );
	VERIFY( ini );
	VERIFY( anims.empty() );
	anims.resize( types_number );
	anims[0] =	xr_new<type_motion0>()->setup( k, ini, section, "kill_enertion"			);	//1.	����������� �������� ������ �� ��������� � ������ 
	anims[1] =	xr_new<type_motion1>()->setup( k, ini, section, "kill_burst"			);	//2.	���������� ������
	anims[2] =	xr_new<type_motion2>()->setup( k, ini, section, "kill_shortgun"			);	//3.	������ 

	anims[6] =	xr_new<type_motion3>()->setup( k, ini, section, "kill_headshot"			);	//4.	������ (�� �����������), ����� 5 (4) 
	anims[4] =	xr_new<type_motion4>()->setup( k, ini, section, "kill_sniper_headshot"	);	//5.	��������� � ������. 
	anims[5] =	xr_new<type_motion5>()->setup( k, ini, section, "kill_sniper_body"		);	//6.	��������� � ����. 
	anims[3] =	xr_new<type_motion6>()->setup( k, ini, section, "kill_grenade"			);	//7.	������ 
	if( ini->line_exist( section , "random_death_animations" )  )
		rnd_anims.setup( k, ini->r_string( section , "random_death_animations" ) ); 
}
