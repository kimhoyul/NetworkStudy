// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyUserWidget.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Kismet/KismetSystemLibrary.h"

void ULobbyUserWidget::SetInfo(ALobbyPlayerState* InPlayerState)
{
	PlayerState = InPlayerState;
	RefreshUI();
}

void ULobbyUserWidget::RefreshUI()
{
	if (PlayerState == nullptr)
		return;

	bool isLocalPlayer = false;

	APlayerController* PlayerController = PlayerState->GetPlayerController();
	if (PlayerController)
		isLocalPlayer = PlayerController->IsLocalController();

	bool isReady = PlayerState->Ready;

	bool isServer = UKismetSystemLibrary::IsServer(this);

	Btn_Ready->SetVisibility(ESlateVisibility::Hidden);
	Btn_KickPlayer->SetVisibility(ESlateVisibility::Hidden);
	Txt_Ready->SetVisibility(ESlateVisibility::Hidden);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Hidden);

	if (isReady)
		Txt_Ready->SetVisibility(ESlateVisibility::Visible);

	if (isLocalPlayer && isReady == false)
		Btn_Ready->SetVisibility(ESlateVisibility::Visible);

	if (isServer && isLocalPlayer == false)
		Btn_KickPlayer->SetVisibility(ESlateVisibility::Visible);

	Editable_PlayerName->SetText(PlayerState->Nickname);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Visible);

	if (isReady)
		Editable_PlayerName->SetIsReadOnly(true);
	else 
		Editable_PlayerName->SetIsReadOnly(!isLocalPlayer);

}
