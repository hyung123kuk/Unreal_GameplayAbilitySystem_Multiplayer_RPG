// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "UI/HKWidgetControllerBase.h"
#include "Interaction/UIPageInterface.h"
#include "UserInfoWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChangeUserInfoValueSignature);

USTRUCT(BlueprintType)
struct FUserInfoWidgetControllerParams
{
	GENERATED_BODY()

	FUserInfoWidgetControllerParams() {}
	FUserInfoWidgetControllerParams(FString& playerName, FString& enterRoomName, FString& introduction ,int playerLevel, int playerExp) :
		PlayerName(playerName),
		EnterRoomName(enterRoomName),
		Introduction(introduction),
		PlayerLevel(playerLevel),
		PlayerExp(playerExp) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString EnterRoomName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Introduction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PlayerExp;

};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UNREALPORTFOLIO_API UUserInfoWidgetController : public UHKWidgetControllerBase, public IUIPageInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FUserInfoWidgetControllerParams& Params);

	virtual FString GetElementName() override;

	UPROPERTY(BlueprintAssignable, Category = "ChangeValue")
	FChangeUserInfoValueSignature ChangeUserInfoValueSignature;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	FString EnterRoomName;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	FString Introduction;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	int PlayerLevel;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	int PlayerExp;
	
};
