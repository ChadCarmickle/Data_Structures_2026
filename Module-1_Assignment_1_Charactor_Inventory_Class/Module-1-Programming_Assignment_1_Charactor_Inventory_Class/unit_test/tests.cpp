#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../character.h"
#include "../inventory.h"
using namespace std;

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

TEST(CharacterTest, DefaultConstructor)
{
    Character character;

    EXPECT_EQ(character.getCharacterName(), "No name assigned");
    EXPECT_EQ(character.getLevel(), 1);
    EXPECT_EQ(character.getHealth(), 100);
    EXPECT_EQ(character.getInventorySize(), 0);
}

TEST(CharacterTest, ParameterizedConstructor)
{
    Character character("Link", 10, 100);

    EXPECT_EQ(character.getCharacterName(), "Link");
    EXPECT_EQ(character.getLevel(), 10);
    EXPECT_EQ(character.getHealth(), 100);
    EXPECT_EQ(character.getInventorySize(), 0);
    Character character2("Zelda", -1, -1);
    EXPECT_NE(character2.getLevel(), -1);
    EXPECT_NE(character2.getHealth(), -1);
}

// -----------------------------------------------------------------------------
// Inventory Management
// -----------------------------------------------------------------------------

TEST(CharacterTest, AddSingleItem)
{
    Character character("Mario", 5, 50);

    Inventory mushroom("Mushroom", "Common", 10);

    character.addItem(mushroom);

    EXPECT_EQ(character.getInventorySize(), 1);
}

TEST(CharacterTest, AddMultipleItems)
{
    Character character("Cloud", 20, 250);

    character.addItem(
        Inventory("Potion", "Common", 20));

    character.addItem(
        Inventory("Phoenix Down", "Rare", 100));

    character.addItem(
        Inventory("Ether", "Uncommon", 50));

    EXPECT_EQ(character.getInventorySize(), 3);
    character.addItem(Inventory("Potion", "Common", 20));
}

TEST(CharacterTest, RemoveItem)
{
    Character character("Samus", 15, 120);

    character.addItem(
        Inventory("Missile", "Common", 5));

    character.addItem(
        Inventory("Energy Tank", "Rare", 100));

    EXPECT_EQ(character.getInventorySize(), 2);

    character.removeItem(0);

    EXPECT_EQ(character.getInventorySize(), 1);
}

// -----------------------------------------------------------------------------
// Copy Constructor
// -----------------------------------------------------------------------------

TEST(CharacterTest, CopyConstructorCopiesCharacterData)
{
    Character original("Zelda", 30, 200);

    original.addItem(
        Inventory("Bow", "Rare", 150));

    original.addItem(
        Inventory("Arrow", "Common", 2));

    Character copy(original);

    EXPECT_EQ(copy.getCharacterName(),
              original.getCharacterName());

    EXPECT_EQ(copy.getLevel(),
              original.getLevel());

    EXPECT_EQ(copy.getHealth(),
              original.getHealth());

    EXPECT_EQ(copy.getInventorySize(),
              original.getInventorySize());
}

TEST(CharacterTest, CopyConstructorPerformsDeepCopy)
{
    Character original("Lara", 18, 125);

    original.addItem(
        Inventory("Pistol", "Common", 50));

    Character copy(original);

    copy.addItem(
        Inventory("Medkit", "Uncommon", 25));

    EXPECT_EQ(original.getInventorySize(), 1);
    EXPECT_EQ(copy.getInventorySize(), 2);
}

// -----------------------------------------------------------------------------
// Assignment Operator
// -----------------------------------------------------------------------------

TEST(CharacterTest, AssignmentOperatorCopiesData)
{
    Character source("Kratos", 40, 500);

    source.addItem(
        Inventory("Axe", "Legendary", 1000));

    Character destination;

    destination = source;

    EXPECT_EQ(destination.getCharacterName(),
              source.getCharacterName());

    EXPECT_EQ(destination.getLevel(),
              source.getLevel());

    EXPECT_EQ(destination.getHealth(),
              source.getHealth());

    EXPECT_EQ(destination.getInventorySize(),
              source.getInventorySize());
}

TEST(CharacterTest, AssignmentOperatorPerformsDeepCopy)
{
    Character source("Master Chief", 60, 1000);

    source.addItem(
        Inventory("Battle Rifle", "Rare", 200));

    Character destination;

    destination = source;

    destination.addItem(
        Inventory("Grenade", "Common", 10));

    EXPECT_EQ(source.getInventorySize(), 1);
    EXPECT_EQ(destination.getInventorySize(), 2);
}

// -----------------------------------------------------------------------------
// Boundary Cases
// -----------------------------------------------------------------------------

TEST(CharacterTest, RemoveItemFromEmptyInventory)
{
    Character character("Pac-Man", 1, 10);

    EXPECT_NO_THROW(character.removeItem(0));

    EXPECT_EQ(character.getInventorySize(), 0);
}

TEST(CharacterTest, SelfAssignment)
{
    Character character("Sonic", 12, 75);

    character.addItem(
        Inventory("Ring", "Common", 1));

    character = character;

    EXPECT_EQ(character.getCharacterName(), "Sonic");
    EXPECT_EQ(character.getInventorySize(), 1);
}

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------

TEST(InventoryTest, DefaultConstructor)
{
    Inventory item;

    EXPECT_EQ(item.getItemName(), "");
    EXPECT_EQ(item.getRarity(), "");
    EXPECT_EQ(item.getValue(), 0);
}

TEST(InventoryTest, ParameterizedConstructor)
{
    Inventory item("Iron Sword", "Common", 100);

    EXPECT_EQ(item.getItemName(), "Iron Sword");
    EXPECT_EQ(item.getRarity(), "Common");
    EXPECT_EQ(item.getValue(), 100);
    Inventory item2("Master Sword", "Rare", -2);
    EXPECT_NE(item2.getValue(), -2);
}

// -----------------------------------------------------------------------------
// Setters
// -----------------------------------------------------------------------------

TEST(InventoryTest, SetItemName)
{
    Inventory item;

    item.setItemName("Magic Staff");

    EXPECT_EQ(item.getItemName(), "Magic Staff");
}

TEST(InventoryTest, SetRarity)
{
    Inventory item;

    item.setRarity("Epic");

    EXPECT_EQ(item.getRarity(), "Epic");
}

TEST(InventoryTest, SetValue)
{
    Inventory item;

    item.setValue(500);

    EXPECT_EQ(item.getValue(), 500);
}

TEST(InventoryTest, SetAllFields)
{
    Inventory item;

    item.setItemName("Dragon Shield");
    item.setRarity("Legendary");
    item.setValue(2500);

    EXPECT_EQ(item.getItemName(), "Dragon Shield");
    EXPECT_EQ(item.getRarity(), "Legendary");
    EXPECT_EQ(item.getValue(), 2500);
}

// -----------------------------------------------------------------------------
// Multiple Objects
// -----------------------------------------------------------------------------

TEST(InventoryTest, MultipleItemsMaintainIndependentValues)
{
    Inventory sword("Sword", "Common", 50);
    Inventory potion("Potion", "Uncommon", 25);

    EXPECT_EQ(sword.getItemName(), "Sword");
    EXPECT_EQ(sword.getRarity(), "Common");
    EXPECT_EQ(sword.getValue(), 50);

    EXPECT_EQ(potion.getItemName(), "Potion");
    EXPECT_EQ(potion.getRarity(), "Uncommon");
    EXPECT_EQ(potion.getValue(), 25);
}

// -----------------------------------------------------------------------------
// Boundary Values
// -----------------------------------------------------------------------------

TEST(InventoryTest, ZeroValueAllowed)
{
    Inventory item("Quest Item", "Unique", 0);

    EXPECT_EQ(item.getValue(), 0);
}

TEST(InventoryTest, LongItemName)
{
    Inventory item;

    item.setItemName(
        "TheAncientSwordOfTheForgottenKingdom");

    EXPECT_EQ(
        item.getItemName(),
        "TheAncientSwordOfTheForgottenKingdom");
}
extern "C" int startTest(int x, char **y)
{
    // cout << "begin" << endl;
    // int x = 0;
    // char ** y = NULL;
    testing::InitGoogleTest(&x, y);
    // cout << "Init Complete"<< endl;
    int code = RUN_ALL_TESTS();
    // exit(code);
    return code;
}
// int i = startTest();
extern "C" int __wrap_main(int x, char **y)
{
    return startTest(x, y);
}