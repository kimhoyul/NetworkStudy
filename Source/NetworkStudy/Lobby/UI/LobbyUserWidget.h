// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyUserWidget.generated.h"

class UTextBlock;
class UEditableTextBox;
class UButton;
class ALobbyPlayerState;

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API ULobbyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UTextBlock> Txt_Ready;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UEditableTextBox> Editable_PlayerName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_KickPlayer;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Ready;

protected:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ALobbyPlayerState> PlayerState;
};
