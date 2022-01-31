#pragma once
#include <Rudy/Core/Symbols.h>
#include <Rudy/Memory/String.h>
#include <Rudy/Memory/Guid.h>
#include <Rudy/Memory/Array.h>
#include <Rudy/Memory/ByteBlock.h>
namespace Rudy
{
	/// <summary>
	/// Contains entity information used in world container
	/// </summary>
	struct RUDY_API WorldEntityInfo
	{
		/// <summary>
		/// Name of the entity
		/// </summary>
		String EntityName;

		/// <summary>
		/// Entity's unique id
		/// </summary>
		Guid ID;
	};

	/// <summary>
	/// Contains component information used in world container
	/// </summary>
	struct RUDY_API WorldComponentInfo
	{
		/// <summary>
		/// Local type index of the component
		/// </summary>
		unsigned int TypeID;

		/// <summary>
		/// Local owner entity index of the components
		/// </summary>
		unsigned int EntityID;
	};

	/// <summary>
	/// Supported field types for components
	/// </summary>
	enum class ComponentFieldCategory
	{
		/// <summary>
		/// This component type is not recognized or corrupted
		/// </summary>
		Undefined = 0,

		/// <summary>
		/// Indicates that this is a custom type and its contents stored as a byte block
		/// </summary>
		Raw = 1,

		/// <summary>
		/// Indicates that this is a component type so its contents stored as a guid
		/// </summary>
		Component = 2,

		/// <summary>
		/// Indicates that this is a asset type so its contents stored as a guid
		/// </summary>
		Asset = 3
	};

	/// <summary>
	/// Contains the required data for representing a component field
	/// </summary>
	struct RUDY_API ComponentFieldEntry
	{
		/// <summary>
		/// Name of the field
		/// </summary>
		String FieldName;

		/// <summary>
		/// Category of the field for further inspection
		/// </summary>
		ComponentFieldCategory Type;

		/// <summary>
		/// Field data represented as a byte block
		/// </summary>
		ByteBlock FieldData;
	};

	/// <summary>
	/// Represents single component and its required meta data to create from the ground
	/// </summary>
	struct RUDY_API ComponentEntry
	{
		/// <summary>
		/// The local id of the owner entity of this component
		/// </summary>
		unsigned int OwnerEntityLocalID;

		/// <summary>
		/// The local id of this component's type
		/// </summary>
		unsigned int LocalTypeID;

		/// <summary>
		/// The field entries which this component has
		/// </summary>
		Array<ComponentFieldEntry> Fields;
	};

	/// <summary>
	/// Contains the required information to re-create a world view with its resolvers
	/// </summary>
	struct RUDY_API WorldViewInformation
	{
		/// <summary>
		/// The local type id of this world view
		/// </summary>
		unsigned int LocalTypeID;

		/// <summary>
		/// The local ids of the resolvers this world view has
		/// </summary>
		Array<unsigned int> ResolverLocalTypeIDs;
	};

	/// <summary>
	/// Contains the required minimal information to re-create a world
	/// </summary>
	struct RUDY_API WorldContainer
	{
		/// <summary>
		/// Total type names this world contains
		/// </summary>
		Array<String> TypeNames;

		/// <summary>
		/// Total assets this world contains
		/// </summary>
		Array<Guid> AssetIDs;

		/// <summary>
		/// Total entity information this world contains
		/// </summary>
		Array<WorldEntityInfo> EntityInformations;

		/// <summary>
		/// Total component informations this world contains
		/// </summary>
		Array<WorldComponentInfo> ComponentInformations;

		/// <summary>
		/// Custom data of the each component
		/// </summary>
		Array<ComponentEntry> ComponentEntries;
	};
}