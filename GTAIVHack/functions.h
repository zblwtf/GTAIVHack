#pragma once
#include <stdint.h>
#include <ctype.h>
#include "Classess.h"
#include "NativeFunction.h"
#include "NativeInvoke.h"
namespace NativeCall
{
	typedef int32_t RET_VOID;
	typedef int32_t RET_ANY;

	namespace Player
	{
		//static void AddScore(Player playerIndex, i32 score) { NativeInvoke::Invoke<ScriptVoid>("ADD_SCORE", playerIndex, score); }
		//static void AllowPlayerToCarryNonMissionObjects(Player playerIndex, b8 allow) { NativeInvoke::Invoke<ScriptVoid>("ALLOW_PLAYER_TO_CARRY_NON_MISSION_OBJECTS", playerIndex, allow); }
		//static void AlterWantedLevel(Player playerIndex, u32 level) { NativeInvoke::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL", playerIndex, level); }
		//static void AlterWantedLevelNoDrop(Player playerIndex, u32 level) { NativeInvoke::Invoke<ScriptVoid>("ALTER_WANTED_LEVEL_NO_DROP", playerIndex, level); }
		//static void ApplyWantedLevelChangeNow(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("APPLY_WANTED_LEVEL_CHANGE_NOW", playerIndex); }
		//static void ChangePlayerModel(Player playerIndex, eModel model) { NativeInvoke::Invoke<ScriptVoid>("CHANGE_PLAYER_MODEL", playerIndex, model); }
		//static void ClearPlayerHasDamagedAtLeastOnePed(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
		inline static int32_t ConvertIntToPlayerIndex(u32 playerId) { return NativeInvoke::Invoke<int32_t>("CONVERT_INT_TO_PLAYERINDEX", playerId); }
		//static void ClearWantedLevel(Player playerIndex) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_WANTED_LEVEL", playerIndex); }
		//static void CreatePlayer(u32 playerId, f32 x, f32 y, f32 z, Player* pPlayerIndex) { NativeInvoke::Invoke<ScriptVoid>("CREATE_PLAYER", playerId, x, y, z, pPlayerIndex); }
		//static void DisablePlayerLockon(Player playerIndex, b8 disabled) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_PLAYER_LOCKON", playerIndex, disabled); }
		//static void DisablePlayerSprint(Player playerIndex, b8 disabled) { NativeInvoke::Invoke<ScriptVoid>("DISABLE_PLAYER_SPRINT", playerIndex, disabled); }
		inline static void GetPlayerChar(int32_t playerIndex, int32_t* pPed) {  NativeInvoke::Invoke<int32_t>("GET_PLAYER_CHAR", playerIndex, pPed); }
		inline static uint32_t GetLocalPlayerId() { return NativeInvoke::Invoke<uint32_t>("GET_PLAYER_ID"); }
		inline static void GetPlayerGroup(int32_t playerIndex, int32_t* pGroup) { NativeInvoke::Invoke<int32_t>("GET_PLAYER_GROUP", playerIndex, pGroup); }
		inline static void GetPlayerMaxArmour(int32_t playerIndex, uint32_t* pMaxArmour) { NativeInvoke::Invoke<int32_t>("GET_PLAYER_MAX_ARMOUR", playerIndex, pMaxArmour); }
		inline static const char* GetPlayerName(int32_t playerIndex) { return NativeInvoke::Invoke<const char*>("GET_PLAYER_NAME", playerIndex); }
		//static u32 GetTimeSincePlayerDroveAgainstTraffic(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_AGAINST_TRAFFIC", playerIndex); }
		//static u32 GetTimeSincePlayerDroveOnPavement(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_DROVE_ON_PAVEMENT", playerIndex); }
		//static u32 GetTimeSincePlayerHitBuilding(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_BUILDING", playerIndex); }
		//static u32 GetTimeSincePlayerHitCar(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_CAR", playerIndex); }
		//static u32 GetTimeSincePlayerHitObject(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_OBJECT", playerIndex); }
		//static u32 GetTimeSincePlayerHitPed(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_HIT_PED", playerIndex); }
		//static u32 GetTimeSincePlayerRanLight(Player playerIndex) { return NativeInvoke::Invoke<u32>("GET_TIME_SINCE_PLAYER_RAN_LIGHT", playerIndex); }
		//static b8 HasPlayerDamagedAtLeastOnePed(Player playerIndex) { return NativeInvoke::Invoke<b8>("HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED", playerIndex); }
		inline static bool IsPlayerClimbing(int32_t playerIndex) { return NativeInvoke::Invoke<bool>("IS_PLAYER_CLIMBING", playerIndex); }
		//static b8 IsPlayerControlOn(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_CONTROL_ON", playerIndex); }
		inline static bool IsPlayerDead(int32_t playerIndex) { return NativeInvoke::Invoke<bool>("IS_PLAYER_DEAD", playerIndex); }
		//static b8 IsPlayerFreeAimingAtChar(Player playerIndex, Ped ped) { return NativeInvoke::Invoke<b8>("IS_PLAYER_FREE_AIMING_AT_CHAR", playerIndex, ped); }
		//static b8 IsPlayerFreeForAmbientTask(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_FREE_FOR_AMBIENT_TASK", playerIndex); }
		//static b8 IsPlayerPlaying(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_PLAYING", playerIndex); }
		//static b8 IsPlayerPressingHorn(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_PRESSING_HORN", playerIndex); }
		//static b8 IsPlayerTargettingAnything(Player playerIndex) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_ANYTHING", playerIndex); }
		//static b8 IsPlayerTargettingChar(Player playerIndex, Ped ped) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_CHAR", playerIndex, ped); }
		//static b8 IsPlayerTargettingObject(Player playerIndex, Object obj) { return NativeInvoke::Invoke<b8>("IS_PLAYER_TARGETTING_OBJECT", playerIndex, obj); }
		//static b8 IsScoreGreater(Player playerIndex, u32 score) { return NativeInvoke::Invoke<b8>("IS_SCORE_GREATER", playerIndex, score); }
		//static b8 IsWantedLevelGreater(Player playerIndex, u32 level) { return NativeInvoke::Invoke<b8>("IS_WANTED_LEVEL_GREATER", playerIndex, level); }
		inline static bool PlayerHasChar(int32_t playerIndex) { return NativeInvoke::Invoke<bool>("PLAYER_HAS_CHAR", playerIndex); }
		//static b8 PlayerHasFlashingStarsAboutToDrop(Player playerIndex) { return NativeInvoke::Invoke<b8>("PLAYER_HAS_FLASHING_STARS_ABOUT_TO_DROP", playerIndex); }
		//static b8 PlayerHasGreyedOutStars(Player playerIndex) { return NativeInvoke::Invoke<b8>("PLAYER_HAS_GREYED_OUT_STARS", playerIndex); }
		//static void RegisterPlayerRespawnCoords(Player playerIndex, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("REGISTER_PLAYER_RESPAWN_COORDS", playerIndex, x, y, z); }
		//static void SetPlayerCanBeHassledByGangs(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_BE_HASSLED_BY_GANGS", playerIndex, value); }
		//static void SetPlayerCanDoDriveBy(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_DO_DRIVE_BY", playerIndex, value); }
		//static void SetPlayerCanUseCover(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CAN_USE_COVER", playerIndex, value); }
		//static void SetPlayerControl(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL", playerIndex, value); }
		//static void SetPlayerControlAdvanced(Player playerIndex, b8 unknown1, b8 unknown2, b8 unknown3) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_CONTROL_ADVANCED", playerIndex, unknown1, unknown2, unknown3); }
		//static void SetPlayerGroupToFollowAlways(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_GROUP_TO_FOLLOW_ALWAYS", playerIndex, value); }
		//static void SetPlayerInvincible(Player playerIndex, b8 value) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_INVINCIBLE", playerIndex, value); }
		inline static void SetPlayerMoodNormal(int32_t playerIndex) { NativeInvoke::Invoke<int32_t>("SET_PLAYER_MOOD_NORMAL", playerIndex); }
		//static void SetPlayerMoodPissedOff(Player playerIndex, u32 unknown150) { NativeInvoke::Invoke<ScriptVoid>("SET_PLAYER_MOOD_PISSED_OFF", playerIndex, unknown150); }
		//static void RemovePlayerHelmet(Player playerIndex, b8 remove) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PLAYER_HELMET", playerIndex, remove); }
	}
	namespace Char
	{
		//static void AddAmmoToChar(Ped ped, eWeapon weapon, i32 amount) { NativeInvoke::Invoke<ScriptVoid>("ADD_AMMO_TO_CHAR", ped, weapon, amount); }
		inline static void AddArmourToChar(int32_t ped, i32 amount) { NativeInvoke::Invoke<int32_t>("ADD_ARMOUR_TO_CHAR", ped, amount); }
		//static void ClearAllCharProps(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ALL_CHAR_PROPS", ped); }
		//static void ClearCharLastDamageBone(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_BONE", ped); }
		//static void ClearCharLastDamageEntity(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_DAMAGE_ENTITY", ped); }
		//static void ClearCharLastWeaponDamage(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_LAST_WEAPON_DAMAGE", ped); }
		//static void ClearCharProp(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_PROP", ped, unknown); }
		//static void ClearCharSecondaryTask(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_SECONDARY_TASK", ped); }
		//static void ClearCharTasks(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS", ped); }
		//static void ClearCharTasksImmediately(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_CHAR_TASKS_IMMEDIATELY", ped); }
		//static void ClearRoomForChar(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("CLEAR_ROOM_FOR_CHAR", ped); }
		//static void CreateChar(u32 type, eModel model, f32 x, f32 y, f32 z, Ped* pPed, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("CREATE_CHAR", type, model, x, y, z, pPed, unknownTrue); }
		//static void CreateRandomChar(f32 x, f32 y, f32 z, Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR", x, y, z, pPed); }
		//static void CreateRandomCharAsDriver(Vehicle vehicle, Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_CHAR_AS_DRIVER", vehicle, pPed); }
		//static void CreateRandomFemaleChar(f32 x, f32 y, f32 z, Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_FEMALE_CHAR", x, y, z, pPed); }
		//static void CreateRandomMaleChar(f32 x, f32 y, f32 z, Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("CREATE_RANDOM_MALE_CHAR", x, y, z, pPed); }
		//static void DamageChar(Ped ped, u32 hitPoints, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DAMAGE_CHAR", ped, hitPoints, unknown); }
		//static void DamagePedBodyPart(Ped ped, ePedBodyPart part, u32 hitPoints) { NativeInvoke::Invoke<ScriptVoid>("DAMAGE_PED_BODY_PART", ped, part, hitPoints); }
		//static void DeleteChar(Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("DELETE_CHAR", pPed); }
		//static void DetachPed(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DETACH_PED", ped, unknown); }
		//static void DetachPedFromWithinCar(Ped ped, b8 unknown) { NativeInvoke::Invoke<ScriptVoid>("DETACH_PED_FROM_WITHIN_CAR", ped, unknown); }
		//static b8 DoesCharExist(Ped ped) { return NativeInvoke::Invoke<b8>("DOES_CHAR_EXIST", ped); }
		//static void DropObject(Ped ped, b8 unknownTrue) { NativeInvoke::Invoke<ScriptVoid>("DROP_OBJECT", ped, unknownTrue); }
		//static void ExplodeCharHead(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("EXPLODE_CHAR_HEAD", ped); }
		inline static void ExtinguishCharFire(int32_t ped) { NativeInvoke::Invoke<int32_t>("EXTINGUISH_CHAR_FIRE", ped); }
		//static void FirePedWeapon(Ped ped, f32 x, f32 y, f32 z) { NativeInvoke::Invoke<ScriptVoid>("FIRE_PED_WEAPON", ped, x, y, z); }
		//static void ForceCharToDropWeapon(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("FORCE_CHAR_TO_DROP_WEAPON", ped); }
		//static ScriptAny ForcePedPinnedDown(Ped ped, b8 force, u32 timerMaybe) { return NativeInvoke::Invoke<ScriptAny>("FORCE_PED_PINNED_DOWN", ped, force, timerMaybe); }
		//static void FreezeCharPosition(Ped ped, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION", ped, frozen); }
		//static void FreezeCharPositionAndDontLoadCollision(Ped ped, b8 frozen) { NativeInvoke::Invoke<ScriptVoid>("FREEZE_CHAR_POSITION_AND_DONT_LOAD_COLLISION", ped, frozen); }
		//static void GetAmmoInCharWeapon(Ped ped, eWeapon weapon, u32* pAmmo) { NativeInvoke::Invoke<ScriptVoid>("GET_AMMO_IN_CHAR_WEAPON", ped, weapon, pAmmo); }
		//static b8 GetAmmoInClip(Ped ped, eWeapon weapon, u32* pAmmo) { return NativeInvoke::Invoke<b8>("GET_AMMO_IN_CLIP", ped, weapon, pAmmo); }
		//static const ch* GetAnimGroupFromChar(Ped ped) { return NativeInvoke::Invoke<const ch*>("GET_ANIM_GROUP_FROM_CHAR", ped); }
		inline static void GetCharCoordinates(int32_t ped, float* pX, float* pY, float* pZ) { NativeInvoke::Invoke<int32_t>("GET_CHAR_COORDINATES", ped, pX, pY, pZ); }
		inline static void GetCharHealth(int32_t ped, i32* pHealth) { NativeInvoke::Invoke<int32_t>("GET_CHAR_HEALTH", ped, pHealth); }
		//static void GetCharAnimCurrentTime(Ped ped, const ch* animGroup, const ch* animName, f32* pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_ANIM_CURRENT_TIME", ped, animGroup, animName, pValue); }
		//static void GetCharAnimTotalTime(Ped ped, const ch* animGroup, const ch* animName, f32* pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_ANIM_TOTAL_TIME", ped, animGroup, animName, pValue); }
		inline static void GetCharArmour(int32_t ped, i32* pArmour) { NativeInvoke::Invoke<int32_t>("GET_CHAR_ARMOUR", ped, pArmour); }
		//static u32 GetCharDrawableVariation(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<ScriptAny>("GET_CHAR_DRAWABLE_VARIATION", ped, component); }
		//static void GetCharExtractedDisplacement(Ped ped, b8 unknown, f32* pX, f32* pY, f32* pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_EXTRACTED_DISPLACEMENT", ped, unknown, pX, pY, pZ); }
		inline static void GetCharHeading(int32_t ped, f32* pValue) { NativeInvoke::Invoke<int32_t>("GET_CHAR_HEADING", ped, pValue); }
		//static void GetCharHeightAboveGround(Ped ped, f32* pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_HEIGHT_ABOVE_GROUND", ped, pValue); }
		//static ScriptAny GetCharLastDamageBone(Ped ped, ePedBone* pBone) { return NativeInvoke::Invoke<ScriptAny>("GET_CHAR_LAST_DAMAGE_BONE", ped, pBone); }
		//static b8 GetCharMeleeActionFlag0(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG0", ped); }
		//static b8 GetCharMeleeActionFlag1(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_MELEE_ACTION_FLAG1", ped); }
		//static void GetCharModel(Ped ped, eModel* pModel) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_MODEL", ped, pModel); }
		inline static uint32_t GetCharMoney(int32_t ped) { return NativeInvoke::Invoke<uint32_t>("GET_CHAR_MONEY", ped); }
		//static void GetCharPropIndex(Ped ped, b8 unknown, u32* pIndex) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_PROP_INDEX", ped, unknown, pIndex); }
		//static b8 GetCharReadyToBeExecuted(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_READY_TO_BE_EXECUTED", ped); }
		//static b8 GetCharReadyToBeStunned(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_READY_TO_BE_STUNNED", ped); }
		//static void GetCharSpeed(Ped ped, f32* pValue) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_SPEED", ped, pValue); }
		//static u32 GetCharTextureVariation(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", ped, component); }
		inline static void GetCharVelocity(int32_t ped, f32* pX, f32* pY, f32* pZ) { NativeInvoke::Invoke<int32_t>("GET_CHAR_VELOCITY", ped, pX, pY, pZ); }
		//static void GetCharWeaponInSlot(Ped ped, eWeaponSlot slot, eWeapon* pWeapon, ScriptAny* pUnknown1, ScriptAny* pUnknown2) { NativeInvoke::Invoke<ScriptVoid>("GET_CHAR_WEAPON_IN_SLOT", ped, slot, pWeapon, pUnknown1, pUnknown2); }
		//static b8 GetCharWillCowerInsteadOfFleeing(Ped ped) { return NativeInvoke::Invoke<b8>("GET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", ped); }
		//static ScriptAny GetCurrentCharWeapon(Ped ped, eWeapon* pWeapon) { return NativeInvoke::Invoke<ScriptAny>("GET_CURRENT_CHAR_WEAPON", ped, pWeapon); }
		//static u32 GetDamageToPedBodyPart(Ped ped, ePedBodyPart part) { return NativeInvoke::Invoke<u32>("GET_DAMAGE_TO_PED_BODY_PART", ped, part); }
		//static void GetDeadCharCoordinates(Ped ped, f32* pX, f32* pY, f32* pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_DEAD_CHAR_COORDINATES", ped, pX, pY, pZ); }
		//static void GetDeadCharPickupCoords(Ped ped, f32* pX, f32* pY, f32* pZ) { NativeInvoke::Invoke<ScriptVoid>("GET_DEAD_CHAR_PICKUP_COORDS", ped, pX, pY, pZ); }
		//static void GetKeyForCharInRoom(Ped ped, eInteriorRoomKey* pKey) { NativeInvoke::Invoke<ScriptVoid>("GET_KEY_FOR_CHAR_IN_ROOM", ped, pKey); }
		//static ScriptAny GetMaxAmmo(Ped ped, eWeapon weapon, u32* pMaxAmmo) { return NativeInvoke::Invoke<ScriptAny>("GET_MAX_AMMO", ped, weapon, pMaxAmmo); }
		//static void GetMaxAmmoInClip(Ped ped, eWeapon weapon, u32* pMaxAmmo) { NativeInvoke::Invoke<ScriptVoid>("GET_MAX_AMMO_IN_CLIP", ped, weapon, pMaxAmmo); }
		//static u32 GetNumberOfCharDrawableVariations(Ped ped, ePedComponent component) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_DRAWABLE_VARIATIONS", ped, component); }
		//static u32 GetNumberOfCharTextureVariations(Ped ped, ePedComponent component, u32 unknown1) { return NativeInvoke::Invoke<u32>("GET_NUMBER_OF_CHAR_TEXTURE_VARIATIONS", ped, component, unknown1); }
		//static Object GetObjectPedIsHolding(Ped ped) { return NativeInvoke::Invoke<Object>("GET_OBJECT_PED_IS_HOLDING", ped); }
		//static void GetOffsetFromCharInWorldCoords(Ped ped, f32 x, f32 y, f32 z, f32* pOffX, f32* pOffY, f32* pOffZ) { NativeInvoke::Invoke<ScriptVoid>("GET_OFFSET_FROM_CHAR_IN_WORLD_COORDS", ped, x, y, z, pOffX, pOffY, pOffZ); }
		//static ePedClimbState GetPedClimbState(Ped ped) { return NativeInvoke::Invoke<ePedClimbState>("GET_PED_CLIMB_STATE", ped); }
		inline static void GetPedType(int32_t ped, int32_t* pType) { NativeInvoke::Invoke<int32_t>("GET_PED_TYPE", ped, pType); }
		//static b8 HasCharBeenDamagedByCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CAR", ped, vehicle); }
		//static b8 HasCharBeenDamagedByChar(Ped ped, Ped otherChar, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_CHAR", ped, otherChar, unknownFalse); }
		//static b8 HasCharBeenDamagedByWeapon(Ped ped, eWeapon weapon) { return NativeInvoke::Invoke<b8>("HAS_CHAR_BEEN_DAMAGED_BY_WEAPON", ped, weapon); }
		//static b8 HasCharGotWeapon(Ped ped, eWeapon weapon) { return NativeInvoke::Invoke<b8>("HAS_CHAR_GOT_WEAPON", ped, weapon); }
		//static b8 HasCharSpottedChar(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR", ped, otherChar); }
		//static b8 HasCharSpottedCharInFront(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("HAS_CHAR_SPOTTED_CHAR_IN_FRONT", ped, otherChar); }
		//static b8 IsCharArmed(Ped ped, eWeaponSlot slot) { return NativeInvoke::Invoke<b8>("IS_CHAR_ARMED", ped, slot); }
		inline static bool IsCharDead(int32_t ped) { return NativeInvoke::Invoke<bool>("IS_CHAR_DEAD", ped); }
		//static b8 IsCharDucking(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_DUCKING", ped); }
		//static b8 IsCharFacingChar(Ped ped, Ped otherChar, f32 angle) { return NativeInvoke::Invoke<b8>("IS_CHAR_FACING_CHAR", ped, otherChar, angle); }
		//static b8 IsCharFatallyInjured(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_FATALLY_INJURED", ped); }
		//static b8 IsCharGesturing(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GESTURING", ped); }
		//static b8 IsCharGettingInToACar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GETTING_IN_TO_A_CAR", ped); }
		//static b8 IsCharGettingUp(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_GETTING_UP", ped); }
		//static b8 IsCharHealthGreater(Ped ped, u32 health) { return NativeInvoke::Invoke<b8>("IS_CHAR_HEALTH_GREATER", ped, health); }
		//static b8 IsCharInAir(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AIR", ped); }
		//static b8 IsCharInAngledArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, f32 unknown, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_2D", ped, x1, y1, x2, y2, unknown, unknownFalse); }
		//static b8 IsCharInAngledArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 unknown, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANGLED_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknown, unknownFalse); }
		//static b8 IsCharInAnyBoat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_BOAT", ped); }
		//static b8 IsCharInAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_CAR", ped); }
		//static b8 IsCharInAnyHeli(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_HELI", ped); }
		//static b8 IsCharInAnyPlane(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_PLANE", ped); }
		//static b8 IsCharInAnyPoliceVehicle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_POLICE_VEHICLE", ped); }
		//static b8 IsCharInAnyTrain(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_ANY_TRAIN", ped); }
		//static b8 IsCharInArea2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_2D", ped, x1, y1, x2, y2, unknownFalse); }
		//static b8 IsCharInArea3D(Ped ped, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_3D", ped, x1, y1, z1, x2, y2, z2, unknownFalse); }
		//static b8 IsCharInAreaOnFoot2D(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_AREA_ON_FOOT_2D", ped, x1, y1, x2, y2, unknownFalse); }
		//static b8 IsCharInCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_CAR", ped, vehicle); }
		//static b8 IsCharInFlyingVehicle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_FLYING_VEHICLE", ped); }
		//static b8 IsCharInMeleeCombat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_MELEE_COMBAT", ped); }
		//static b8 IsCharInModel(Ped ped, eModel model) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_MODEL", ped, model); }
		//static b8 IsCharInTaxi(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_TAXI", ped); }
		//static b8 IsCharInWater(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_IN_WATER", ped); }
		//static b8 IsCharInjured(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_INJURED", ped); }
		//static b8 IsCharMale(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_MALE", ped); }
		//static b8 IsCharModel(Ped ped, eModel model) { return NativeInvoke::Invoke<b8>("IS_CHAR_MODEL", ped, model); }
		//static b8 IsCharOnAnyBike(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_ANY_BIKE", ped); }
		inline static bool IsCharOnFire(int32_t ped) { return NativeInvoke::Invoke<bool>("IS_CHAR_ON_FIRE", ped); }
		//static b8 IsCharOnFoot(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_FOOT", ped); }
		inline static bool IsCharOnScreen(int32_t ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_ON_SCREEN", ped); }
		inline static b8 IsCharShooting(int32_t ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SHOOTING", ped); }
		//static b8 IsCharShootingInArea(Ped ped, f32 x1, f32 y1, f32 x2, f32 y2, b8 unknownFalse) { return NativeInvoke::Invoke<b8>("IS_CHAR_SHOOTING_IN_AREA", ped, x1, y1, x2, y2, unknownFalse); }
		//static b8 IsCharSittingIdle(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IDLE", ped); }
		//static b8 IsCharSittingInAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IN_ANY_CAR", ped); }
		//static b8 IsCharSittingInCar(Ped ped, Vehicle vehicle) { return NativeInvoke::Invoke<b8>("IS_CHAR_SITTING_IN_CAR", ped, vehicle); }
		//static b8 IsCharStopped(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_STOPPED", ped); }
		//static b8 IsCharStuckUnderCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_STUCK_UNDER_CAR", ped); }
		inline static b8 IsCharSwimming(int32_t ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_SWIMMING", ped); }
		//static b8 IsCharTouchingChar(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_CHAR", ped, otherChar); }
		//static b8 IsCharTouchingObject(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT", ped, obj); }
		//static b8 IsCharTouchingObjectOnFoot(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_OBJECT_ON_FOOT", ped, obj); }
		//static b8 IsCharTouchingVehicle(ScriptAny p0, ScriptAny p1) { return NativeInvoke::Invoke<b8>("IS_CHAR_TOUCHING_VEHICLE", p0, p1); }
		//static b8 IsCharTryingToEnterALockedCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_TRYING_TO_ENTER_A_LOCKED_CAR", ped); }
		//static b8 IsCharUsingAnyScenario(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_USING_ANY_SCENARIO", ped); }
		//static b8 IsCharUsingScenario(Ped ped, const ch* scenarioName) { return NativeInvoke::Invoke<b8>("IS_CHAR_USING_SCENARIO", ped, scenarioName); }
		//static b8 IsCharVisible(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_VISIBLE", ped); }
		//static b8 IsCharWaitingForWorldCollision(Ped ped) { return NativeInvoke::Invoke<b8>("IS_CHAR_WAITING_FOR_WORLD_COLLISION", ped); }
		//static b8 IsPedAMissionPed(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_A_MISSION_PED", ped); }
		//static b8 IsPedAttachedToAnyCar(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_ATTACHED_TO_ANY_CAR", ped); }
		//static b8 IsPedAttachedToObject(Ped ped, Object obj) { return NativeInvoke::Invoke<b8>("IS_PED_ATTACHED_TO_OBJECT", ped, obj); }
		//static b8 IsPedBeingJacked(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_BEING_JACKED", ped); }
		//static b8 IsPedDoingDriveby(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_DOING_DRIVEBY", ped); }
		//static b8 IsPedFleeing(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_FLEEING", ped); }
		//static b8 IsPedHoldingAnObject(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_HOLDING_AN_OBJECT", ped); }
		//static b8 IsPedInCombat(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_COMBAT", ped); }
		//static b8 IsPedInCover(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_COVER", ped); }
		//static b8 IsPedInGroup(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_IN_GROUP", ped); }
		//static b8 IsPedJacking(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_JACKING", ped); }
		//static b8 IsPedLookingAtPed(Ped ped, Ped otherChar) { return NativeInvoke::Invoke<b8>("IS_PED_LOOKING_AT_PED", ped, otherChar); }
		//static b8 IsPedRagdoll(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_RAGDOLL", ped); }
		//static b8 IsPedRetreating(Ped ped) { return NativeInvoke::Invoke<b8>("IS_PED_RETREATING", ped); }
		//static void MarkCharAsNoLongerNeeded(Ped* pPed) { NativeInvoke::Invoke<ScriptVoid>("MARK_CHAR_AS_NO_LONGER_NEEDED", pPed); }
		//static void ModifyCharMoveState(Ped ped, ePedMoveState state) { NativeInvoke::Invoke<ScriptVoid>("MODIFY_CHAR_MOVE_STATE", ped, state); }
		//static void RemoveAllCharWeapons(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_ALL_CHAR_WEAPONS", ped); }
		//static void RemoveCharDefensiveArea(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_DEFENSIVE_AREA", ped); }
		//static void RemoveCharElegantly(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_ELEGANTLY", ped); }
		//static void RemoveCharFromGroup(Ped ped) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_CHAR_FROM_GROUP", ped); }
		//static ScriptAny SetAmmoInClip(Ped ped, eWeapon weapon, u32 ammo) { return NativeInvoke::Invoke<ScriptAny>("SET_AMMO_IN_CLIP", ped, weapon, ammo); }
		inline static void SetCharHealth(int32_t ped, i32 health) { NativeInvoke::Invoke<int32_t>("SET_CHAR_HEALTH", ped, health); }
		//static void SetCharWillUseCover(Ped ped, CoverPoint coverPoint) { NativeInvoke::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_COVER", ped, coverPoint); }
		//static void SetRoomForCharByKey(Ped ped, eInteriorRoomKey key) { NativeInvoke::Invoke<ScriptVoid>("SET_ROOM_FOR_CHAR_BY_KEY", ped, key); }
		//static void RemovePedHelmet(Ped ped, b8 removed) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_PED_HELMET", ped, removed); }
		//static void RemoveWeaponFromChar(Ped ped, eWeapon weapon) { NativeInvoke::Invoke<ScriptVoid>("REMOVE_WEAPON_FROM_CHAR", ped, weapon); }

		
		//static void ApplyForceToPed(Ped c, u32 uk0_3, f32 pX, f32 pY, f32 pZ, f32 spinX, f32 spinY, f32 spinZ, u32 uk4_0, u32 uk5_1, u32 uk6_1, u32 uk7_1) { Native::Function::Invoke<ScriptVoid>("APPLY_FORCE_TO_PED", c, uk0_3, pX, pY, pZ, spinX, spinY, spinZ, uk4_0, uk5_1, uk6_1, uk7_1); }
		//static void AttachPedToCar(Ped c, Vehicle v, u32 unknown0_0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 unknown1_276, f32 unknown2_0, u32 unknown3_0, u32 unknown4_0) { Native::Function::Invoke<ScriptVoid>("ATTACH_PED_TO_CAR", c, v, unknown0_0, offsetX, offsetY, offsetZ, unknown1_276, unknown2_0, unknown3_0, unknown4_0); }
		//static void BlockCharGestureAnims(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("BLOCK_CHAR_GESTURE_ANIMS", c, value); }
		//static void BlockPedWeaponSwitching(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("BLOCK_PED_WEAPON_SWITCHING", c, value); }
		//static void CancelCurrentlyPlayingAmbientSpeech(Ped c) { Native::Function::Invoke<ScriptVoid>("CANCEL_CURRENTLY_PLAYING_AMBIENT_SPEECH", c); }
		//static void ClearCharProp(Ped ped, u32 proptype) { Native::Function::Invoke<ScriptVoid>("CLEAR_CHAR_PROP", ped, proptype); }
		//static void old_DetachPed(Ped ped, b8 unknown_true) { Native::Function::Invoke<ScriptVoid>("DETACH_PED", ped, unknown_true); }
		//static void ForcePedToFleeWhilstDrivingVehicle(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("FORCE_PED_TO_FLEE_WHILST_DRIVING_VEHICLE", c, v); }
		////static b8 GetAmmoInClip(Ped ped, u32 weapon, u32 *pAmmo) { return Native::Function::Invoke<b8>("GET_AMMO_IN_CLIP", ped, weapon, pAmmo); }
		//static void GetCharPropIndex2(Ped c, u32 proptype, u32* index) { Native::Function::Invoke<ScriptVoid>("GET_CHAR_PROP_INDEX", c, proptype, index); }
		////static u32 GetCharDrawableVariation(Ped c, u32 comptype) { return Native::Function::Invoke<u32>("GET_CHAR_DRAWABLE_VARIATION", c, comptype); }
		////static u32 GetCharTextureVariation(Ped c, u32 comptype) { return Native::Function::Invoke<u32>("GET_CHAR_TEXTURE_VARIATION", c, comptype); }
		//static void GetMaxAmmoInClip(Ped ped, u32 weapon, u32* pMaxAmmo) { Native::Function::Invoke<ScriptVoid>("GET_MAX_AMMO_IN_CLIP", ped, weapon, pMaxAmmo); }
		static void GetPedBonePosition(int32_t c, u32 boneid, f32 pX, f32 pY, f32 pZ, vec3* position) { NativeFunction::Invoke<int32_t>("GET_PED_BONE_POSITION", c, boneid, pX, pY, pZ, position); }
		////static void GetPedBonePosition(Ped c, u32 boneid, f32 pX, f32 pY, f32 pZ, pVector3* position) { Native::Function::Invoke<ScriptVoid>("GET_PED_BONE_POSITION", c, boneid, pX, pY, pZ, position); }
		//static void GivePedFakeNetworkName(Ped ped, char* Name, u8 r, u8 g, u8 b, u8 a) { Native::Function::Invoke<ScriptVoid>("GIVE_PED_FAKE_NETWORK_NAME", ped, Name, r, g, b, a); }
		//static void GivePedHelmet(Ped c) { Native::Function::Invoke<ScriptVoid>("GIVE_PED_HELMET", c); }
		//static void GiveWeaponToChar(Ped c, eWeapon weapon, u32 ammo, u32 unknown0) { Native::Function::Invoke<ScriptVoid>("GIVE_WEAPON_TO_CHAR", c, weapon, ammo, unknown0); }
		//static void GetWeaponTypeModel(i32 weapon, i32* model) { Native::Function::Invoke<ScriptVoid>("GET_WEAPONTYPE_MODEL", weapon, model); }
		//static void GetWeaponTypeSlot(i32 weapon, i32* slot) { Native::Function::Invoke<ScriptVoid>("GET_WEAPONTYPE_SLOT", weapon, slot); }
		//static b8 IsAmbientSpeechPlaying(Ped c) { return Native::Function::Invoke<b8>("IS_AMBIENT_SPEECH_PLAYING", c); }
		//static b8 IsCharPlayingAnim(Ped c, ch* animset, ch* animname) { return Native::Function::Invoke<b8>("IS_CHAR_PLAYING_ANIM", c, animset, animname); }
		////static b8 IsPedAMissionPed(Ped ped) { return Native::Function::Invoke<b8>("IS_PED_A_MISSION_PED", ped); }
		//static b8 IsScriptedSpeechPlaying(Ped c) { return Native::Function::Invoke<b8>("IS_SCRIPTED_SPEECH_PLAYING", c); }
		//static void RemoveFakeNetworkNameFromPed(Ped ped) { Native::Function::Invoke<ScriptVoid>("REMOVE_FAKE_NETWORK_NAME_FROM_PED", ped); }
		//static void ReviveInjuredPed(Ped c) { Native::Function::Invoke<ScriptVoid>("REVIVE_INJURED_PED", c); }
		//static void SayAmbientSpeech(Ped c, ch* phraseid, ScriptAny unknown0_1, ScriptAny unknown1_1, ScriptAny unknown2_0) { Native::Function::Invoke<ScriptVoid>("SAY_AMBIENT_SPEECH", c, phraseid, unknown0_1, unknown1_1, unknown2_0); }
		//static void SetAmbientVoiceName(Ped p, ch* voicename) { Native::Function::Invoke<ScriptVoid>("SET_AMBIENT_VOICE_NAME", p, voicename); }
		//static ScriptAny SetAmmoInClip(Ped ped, u32 weapon, u32 ammo) { return Native::Function::Invoke<ScriptAny>("SET_AMMO_IN_CLIP", ped, weapon, ammo); }
		//static void SetBlockingOfNonTemporaryEvents(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_BLOCKING_OF_NON_TEMPORARY_EVENTS", c, value); }
		//static void SetCharAccuracy(Ped c, u32 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_ACCURACY", c, value); }
		//static void SetCharAmmo(Ped c, eWeapon weapon, u32 ammo) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AMMO", c, weapon, ammo); }
		//static void SetCharAsEnemy(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AS_ENEMY", c, value); }
		//static void SetCharAsMissionChar(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_AS_MISSION_CHAR", c); }
		//static void SetCharCanBeKnockedOffBike(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_KNOCKED_OFF_BIKE", c, value); }
		//static void SetCharCanBeShotInVehicle(Ped ped, b8 enabled) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CAN_BE_SHOT_IN_VEHICLE", ped, enabled); }
		//static void SetCharCantBeDraggedOut(Ped ped, b8 enabled) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_CANT_BE_DRAGGED_OUT", ped, enabled); }
		//static void SetCharComponentVariation(Ped c, u32 comptype, u32 compmodel, u32 comptexture) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_COMPONENT_VARIATION", c, comptype, compmodel, comptexture); }
		inline static void SetCharCoordinates(int32_t c, f32 pX, f32 pY, f32 pZ) { NativeFunction::Invoke<int32_t>("SET_CHAR_COORDINATES", c, pX, pY, pZ); }
		//static void SetCharDefaultComponentVariation(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DEFAULT_COMPONENT_VARIATION", c); }
		//static void SetCharDesiredHeading(Ped c, f32 dir) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DESIRED_HEADING", c, dir); }
		//static void SetCharDropsWeaponsWhenDead(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DROPS_WEAPONS_WHEN_DEAD", c, value); }
		//static void SetCharDruggedUp(Ped ped, b8 drugged) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_DRUGGED_UP", ped, drugged); }
		//static void SetCharFireDamageMultiplier(Ped c, f32 mult) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_FIRE_DAMAGE_MULTIPLIER", c, mult); }
		//static void SetCharGravity(Ped c, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_GRAVITY", c, value); }
		inline static void SetCharHeading(int32_t c, f32 dir) {NativeFunction::Invoke<int32_t>("SET_CHAR_HEADING", c, dir); }
		//static void SetCharInvincible(Ped c, b8 enable) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_INVINCIBLE", c, enable); }
		//static void SetCharIsTargetPriority(Ped c, b8 enable) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_IS_TARGET_PRIORITY", c, enable); }
		inline static void SetCharMaxHealth(int32_t c, i32 value) { NativeFunction::Invoke<int32_t>("SET_CHAR_MAX_HEALTH", c, value); }
		inline static void SetCharMoney(int32_t c, u32 amount) { NativeFunction::Invoke<int32_t>("SET_CHAR_MONEY", c, amount); }
		//static void SetCharNeverLeavesGroup(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_NEVER_LEAVES_GROUP", c, value); }
		//static void SetCharProofs(Ped c, b8 unknown0, b8 FallingDamage, b8 unknown1, b8 unknown2, b8 unknown3) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_PROOFS", c, unknown0, FallingDamage, unknown1, unknown2, unknown3); }
		//static void SetCharPropIndex(Ped c, u32 proptype, u32 index) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_PROP_INDEX", c, proptype, index); }
		//static void SetCharRandomComponentVariation(Ped c) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_RANDOM_COMPONENT_VARIATION", c); }
		//static void SetCharSphereDefensiveArea(Ped c, f32 pX, f32 pY, f32 pZ, f32 radius) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_SPHERE_DEFENSIVE_AREA", c, pX, pY, pZ, radius); }
		//static void SetCharSuffersCriticalHits(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_SUFFERS_CRITICAL_HITS", c, value); }
		inline static void SetCharVelocity(int32_t c, f32 vX, f32 vY, f32 vZ) { NativeFunction::Invoke<int32_t>("SET_CHAR_VELOCITY", c, vX, vY, vZ); }
		inline static void SetCharVisible(int32_t c, b8 value) { NativeFunction::Invoke<int32_t>("SET_CHAR_VISIBLE", c, value); }
		//static void SetCharWantedByPolice(Ped c, b8 wanted) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WANTED_BY_POLICE", c, wanted); }
		//static void SetCharWillCowerInsteadOfFleeing(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_COWER_INSTEAD_OF_FLEEING", c, value); }
		//static void SetCharWillDoDrivebys(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_DO_DRIVEBYS", c, value); }
		//static void SetCharWillFlyThroughWindscreen(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_FLY_THROUGH_WINDSCREEN", c, value); }
		//static void SetCharWillMoveWhenInjured(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_MOVE_WHEN_INJURED", c, value); }
		//static void SetCharWillUseCarsInCombat(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_CHAR_WILL_USE_CARS_IN_COMBAT", c, value); }
		//static void SetCurrentCharWeapon(Ped c, eWeapon w, b8 unknownTrue) { Native::Function::Invoke<ScriptVoid>("SET_CURRENT_CHAR_WEAPON", c, w, unknownTrue); }
		//static void SetGroupCharDucksWhenAimedAt(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_GROUP_CHAR_DUCKS_WHEN_AIMED_AT", c, value); }
		//static void SetIgnoreLowPriorityShockingEvents(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS", c, value); }
		//static void SetPedDiesWhenInjured(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_DIES_WHEN_INJURED", c, value); }
		//static void SetPedIsBlindRaging(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_IS_BLIND_RAGING", c, value); }
		//static void SetPedIsDrunk(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_IS_DRUNK", c, value); }
		//static void SetPedPathMayDropFromHeight(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_DROP_FROM_HEIGHT", c, value); }
		//static void SetPedPathMayUseClimbovers(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_CLIMBOVERS", c, value); }
		//static void SetPedPathMayUseLadders(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("SET_PED_PATH_MAY_USE_LADDERS", c, value); }
		//static void SetSenseRange(Ped c, f32 value) { Native::Function::Invoke<ScriptVoid>("SET_SENSE_RANGE", c, value); }
		//static void SetVoiceIdFromHeadComponent(Ped p, b8 unknown_false, b8 ismale) { Native::Function::Invoke<ScriptVoid>("SET_VOICE_ID_FROM_HEAD_COMPONENT", p, unknown_false, ismale); }
		inline static int32_t StartCharFire(int32_t c) { return NativeFunction::Invoke<int32_t>("START_CHAR_FIRE", c); }
		//static void SwitchPedToAnimated(Ped c, b8 instantly) { Native::Function::Invoke<ScriptVoid>("SWITCH_PED_TO_ANIMATED", c, instantly); }
		//static ScriptAny SwitchPedToRagdoll(Ped c, u32 unknown1_10000, i32 duration, u32 nm_behavior, u32 unknown4_1, u32 unknown5_1, u32 unknown6_0) { return Native::Function::Invoke<ScriptAny>("SWITCH_PED_TO_RAGDOLL", c, unknown1_10000, duration, nm_behavior, unknown4_1, unknown5_1, unknown6_0); }
		//static void UnlockRagdoll(Ped c, b8 value) { Native::Function::Invoke<ScriptVoid>("UNLOCK_RAGDOLL", c, value); }
		//static void WarpCharFromCarToCoord(Ped c, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_COORD", c, pX, pY, pZ); }
		//static void WarpCharIntoCar(Ped c, Vehicle v) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR", c, v); }
		//static void WarpCharIntoCarAsPassenger(Ped c, Vehicle v, u32 seat) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_INTO_CAR_AS_PASSENGER", c, v, seat); }
		//static void WarpCharFromCarToCar(Ped c, Vehicle v, u32 seat) { Native::Function::Invoke<ScriptVoid>("WARP_CHAR_FROM_CAR_TO_CAR", c, v, seat); }




		
	}
	namespace Camera
	{
		// CAMERA
		//static void ActivateScriptedCams(b8 on_1, b8 on_2) { Native::Function::Invoke<ScriptVoid>("ACTIVATE_SCRIPTED_CAMS", on_1, on_2); }
		//static b8 AreAllNavmeshRegionsLoaded() { return Native::Function::Invoke<b8>("ARE_ALL_NAVMESH_REGIONS_LOADED"); }
		//static void BeginCamCommands(i32* camera) { Native::Function::Invoke<ScriptVoid>("BEGIN_CAM_COMMANDS", camera); }
		//static b8 CamIsSphereVisible(i32 camera, f32 pX, f32 pY, f32 pZ, f32 radius) { return Native::Function::Invoke<b8>("CAM_IS_SPHERE_VISIBLE", camera, pX, pY, pZ, radius); }
		static void CreateCam(i32 camtype_usually14, u32* camera) { NativeFunction::Invoke<RET_VOID>("CREATE_CAM", camtype_usually14, camera); }
		//static void DestroyCam(i32 camera) { Native::Function::Invoke<ScriptVoid>("DESTROY_CAM", camera); }
		//static b8 DoesCamExist(i32 camera) { return Native::Function::Invoke<b8>("DOES_CAM_EXIST", camera); }
		//static void EndCamCommands(i32* camera) { Native::Function::Invoke<ScriptVoid>("END_CAM_COMMANDS", camera); }
		//static void SetCamActive(i32 camera, bool value) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ACTIVE", camera, value); }
		static void GetCamFov(i32 camera, f32* fov) { NativeFunction::Invoke<RET_VOID>("GET_CAM_FOV", camera, fov); }
		static void GetCamPos(i32 camera, f32* pX, f32* pY, f32* pZ) { NativeFunction::Invoke<RET_VOID>("GET_CAM_POS", camera, pX, pY, pZ); }
		static void GetCamRot(i32 camera, f32* angleX, f32* angleY, f32* angleZ) { NativeFunction::Invoke<RET_VOID>("GET_CAM_ROT", camera, angleX, angleY, angleZ); }
		static void GetGameCam(i32* camera) { NativeFunction::Invoke<RET_VOID>("GET_GAME_CAM", camera); }
		static void GetGameCamChild(i32* camera) { NativeFunction::Invoke<RET_VOID>("GET_GAME_CAM_CHILD", camera); }
		static void GetRootCam(i32* camera) { NativeFunction::Invoke<RET_VOID>("GET_ROOT_CAM", camera); }
		//static bool IsCamActive(i32 camera) { return Native::Function::Invoke<bool>("IS_CAM_ACTIVE", camera); }
		//static bool IsCamInterpolating() { return Native::Function::Invoke<bool>("IS_CAM_INTERPOLATING"); }
		//static bool IsCamPropagating(i32 camera) { return Native::Function::Invoke<bool>("IS_CAM_PROPAGATING", camera); }
		//static void PointCamAtCoord(i32 camera, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_COORD", camera, pX, pY, pZ); }
		//static void PointCamAtObject(i32 camera, i32 obj) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_OBJECT", camera, obj); }
		//static void PointCamAtPed(i32 camera, i32 ped) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_PED", camera, ped); }
		//static void PointCamAtVehicle(i32 camera, i32 car) { Native::Function::Invoke<ScriptVoid>("POINT_CAM_AT_VEHICLE", camera, car); }
		//static void SetCamFov(i32 camera, f32 fov) { Native::Function::Invoke<ScriptVoid>("SET_CAM_FOV", camera, fov); }
		//static void SetCamInFrontOfPed(Ped ped) { Native::Function::Invoke<ScriptVoid>("SET_CAM_IN_FRONT_OF_PED", ped); }
		//static void SetCamPos(i32 camera, f32 pX, f32 pY, f32 pZ) { Native::Function::Invoke<ScriptVoid>("SET_CAM_POS", camera, pX, pY, pZ); }
		//static void SetCamPropagate(i32 camera, bool value) { Native::Function::Invoke<ScriptVoid>("SET_CAM_PROPAGATE", camera, value); }
		//static void SetCamRot(i32 camera, f32 angleX, f32 angleY, f32 angleZ) { Native::Function::Invoke<ScriptVoid>("SET_CAM_ROT", camera, angleX, angleY, angleZ); }
		//static void SetCamTargetPed(i32 camera, Ped ped) { Native::Function::Invoke<ScriptVoid>("SET_CAM_TARGET_PED", camera, ped); }
		//static void SetDrunkCam(i32 camera, f32 intensity, i32 duration) { Native::Function::Invoke<ScriptVoid>("SET_DRUNK_CAM", camera, intensity, duration); }
	}
	// Player
	
}
