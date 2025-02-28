// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Items/ItemObject.h"

UItemObject::UItemObject()
{
	Dimensions = FIntPoint(1, 1);
	Icon = nullptr;
	RIcon = nullptr;
	bRotated = false;
	ItemActorClass = nullptr;

	StackCount = 1;
}

void UItemObject::InitializeItemObject(int32 dimensionX, int32 dimensionY, UMaterialInterface* InIcon, UMaterialInterface* InRIcon, TSubclassOf<AItemActor> itemClass, const int32 NewStackCount)
{
	Dimensions = FIntPoint(dimensionX, dimensionY);
	Icon = InIcon;
	RIcon = InRIcon;
	ItemActorClass = itemClass;

	StackCount = NewStackCount;
}

FIntPoint UItemObject::GetDimensions() const
{
	if (bRotated)
	{
		return FIntPoint(Dimensions.Y, Dimensions.X);
	}
	return Dimensions;
}

UMaterialInterface* UItemObject::GetItemImage() const
{
	if (bRotated)
	{
		return RIcon;
	}
	return Icon;
}
