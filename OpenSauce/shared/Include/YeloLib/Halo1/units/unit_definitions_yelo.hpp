/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#pragma once

#include <YeloLib/tag_files/tag_groups_base_yelo.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum unit_seat_keyframe_action_self_seat_action : _enum
		{
			_unit_seat_keyframe_action_self_seat_action_none,
			_unit_seat_keyframe_action_self_seat_action_exit_current,
			_unit_seat_keyframe_action_self_seat_action_enter_target,

			_unit_seat_keyframe_action_seat_action_self
		};

		enum unit_seat_keyframe_action_target_seat_unit_action : _enum
		{
			_unit_seat_keyframe_action_target_seat_unit_action_none,
			_unit_seat_keyframe_action_target_seat_unit_action_exit_seat,
			_unit_seat_keyframe_action_target_seat_unit_action_eject_from_seat,

			_unit_seat_keyframe_action_seat_action_target
		};

		enum unit_seat_keyframe_action_apply_effect : _enum
		{
			_unit_seat_keyframe_action_apply_effect_none,
			_unit_seat_keyframe_action_apply_effect_mounted_unit,
			_unit_seat_keyframe_action_apply_effect_seated_unit,

			_unit_seat_keyframe_action_apply_effect
		};

		enum unit_seat_boarding_type : _enum
		{
			_unit_seat_boarding_type_immediate,
			_unit_seat_boarding_type_delayed,

			_unit_seat_boarding_type
		};

		enum unit_seat_boarding_vitality_threshold_source : _enum
		{
			_unit_seat_boarding_vitality_threshold_source_mounted_unit,
			_unit_seat_boarding_vitality_threshold_source_seated_unit,

			_unit_seat_boarding_vitality_threshold_source
		};

		enum unit_seat_damage_melee : _enum
		{
			_unit_seat_damage_melee_normal,
			_unit_seat_damage_melee_mounted_unit,
			_unit_seat_damage_melee_target_seat_unit,

			_unit_seat_damage_melee
		};

		enum unit_seat_damage_grenade : _enum
		{
			_unit_seat_damage_grenade_normal,
			_unit_seat_damage_grenade_disabled,
			_unit_seat_damage_grenade_plant_on_mounted_unit,
			_unit_seat_damage_grenade_plant_on_target_seat_unit,

			_unit_seat_damage_grenade
		};
	};
	
	namespace Flags
	{
		enum unit_seat_extensions_flags
		{
			_unit_seat_extensions_flags_requires_target_seat_occupied_bit,
			_unit_seat_extensions_flags_exit_on_unit_death_bit,
			_unit_seat_extensions_flags_restrict_by_unit_sight_bit,
			_unit_seat_extensions_flags_restrict_by_unit_shield_bit,
			_unit_seat_extensions_flags_restrict_by_unit_health_bit,
			_unit_seat_extensions_flags_restrict_by_ai_state_bit,

			_unit_seat_extensions_flags
		};

		enum unit_seat_keyframe_action_flags
		{
			_unit_seat_keyframe_action_flags_control_powered_seat_bit,

			_unit_seat_keyframe_action_flags
		};

		enum unit_seat_boarding_delay_until_flags
		{
			_unit_seat_boarding_delay_until_flags_empty_target_seat_bit,
			_unit_seat_boarding_delay_until_flags_unit_shield_threshold_bit,
			_unit_seat_boarding_delay_until_flags_unit_health_threshold_bit,

			_unit_seat_boarding_delay_until_flags
		};

		enum unit_seat_damage_flags
		{
			_unit_seat_damage_flags_use_weapon_melee_bit,
			_unit_seat_damage_flags_exit_after_grenade_plant_bit,

			_unit_seat_damage_flags
		};
	};

	namespace TagGroups
	{
		struct unit_seat_keyframe_action
		{
			TAG_FIELD(word_flags, flags);
			TAG_FIELD(Enums::unit_seat_keyframe_action_self_seat_action, self_seat_action);
			TAG_FIELD(Enums::unit_seat_keyframe_action_target_seat_unit_action, target_seat_unit_action);
			PAD16;

			TAG_FIELD(Enums::unit_seat_keyframe_action_apply_effect, apply_damage_to);
			PAD16;
			TAG_FIELD(tag_reference, damage_effect, "jpt!");

			TAG_FIELD(Enums::unit_seat_keyframe_action_apply_effect, apply_effect_to);
			PAD16;
			TAG_FIELD(tag_reference, effect, "effe");
			TAG_FIELD(tag_string, effect_marker);
		};

		struct unit_seat_boarding
		{
			TAG_FIELD(Enums::unit_seat_boarding_type, boarding_type);
			TAG_FIELD(word_flags, delay_until);
			TAG_FIELD(Enums::unit_seat_boarding_vitality_threshold_source, unit_vitality_source);
			PAD16;
			TAG_FIELD(real_fraction, unit_shield_threshold);
			TAG_FIELD(real_fraction, unit_health_threshold);

			unit_seat_keyframe_action primary_keyframe_action;
			unit_seat_keyframe_action final_keyframe_action;
		};

		struct unit_seat_damage
		{
			TAG_FIELD(word_flags, flags);
			TAG_FIELD(Enums::unit_seat_damage_melee, melee);
			TAG_FIELD(tag_reference, melee_damage_effect, "jpt!");
			TAG_FIELD(Enums::unit_seat_damage_grenade, grenade);
			TAG_FIELD(real, grenade_detonation_time_scale);
			TAG_FIELD(tag_string, grenade_marker);
		};

		struct unit_seat_extensions
		{
			TAG_FIELD(word_flags, flags);
			TAG_FIELD(int16, target_seat_index);
			TAG_TBLOCK(seat_targeting_seats, int16);

			TAG_FIELD(angle, unit_sight_angle);
			TAG_FIELD(real_fraction, unit_shield_threshold);
			TAG_FIELD(real_fraction, unit_health_threshold);
			TAG_FIELD(word_flags, permitted_ai_states);
			PAD16;
			TAG_PAD(tag_block, 2);
			TAG_TBLOCK(seat_boarding, unit_seat_boarding);
			TAG_TBLOCK(seat_damage, unit_seat_damage);
			TAG_PAD(tag_block, 4);
		};
	};
};