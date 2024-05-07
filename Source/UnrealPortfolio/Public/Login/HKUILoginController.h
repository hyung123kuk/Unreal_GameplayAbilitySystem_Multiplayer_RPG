// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Player/HKUIPlayerControllerBase.h"
#include "HKUILoginController.generated.h"



/**
 * 
 */
UCLASS()
class UNREALPORTFOLIO_API AHKUILoginController : public AHKUIPlayerControllerBase
{
	GENERATED_BODY()
	
public:
	AHKUILoginController();
	
	UFUNCTION(Client, Reliable)
	void ResponseFromServerToClient_Client(const FString& Message, EServerToClientMessageType MessageType, bool Success);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void CheckIDForSignUp_Server(const FString& ID);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void SignUp_Server(const FString& ID, const FString& Password,const FString& PasswordConfirm);

	virtual void ReceiveServerMessage(const FString& Message, EServerToClientMessageType MessageType, bool PopupMessage = false, bool Success = false) override;

public:
	UPROPERTY(BlueprintAssignable, Category = "SuccessOrNot||CheckID")
	FMessageSuccessOrNotDelegate CheckIDSuccessOrNotDelegate;

};