// Fill out your copyright notice in the Description page of Project Settings.



#include "LoginWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "../../TGameInstance.h"


void ULoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginButtonClicked);
	}
}

void ULoginWidget::OnLoginButtonClicked()
{
	if (IdInputTextBox && PasswordInputTextBox)
	{
		FText Id = IdInputTextBox->GetText();
		FText Password = PasswordInputTextBox->GetText();

		FString IdString = Id.ToString();
		FString PasswordString = Password.ToString();

		UE_LOG(LogTemp, Warning, TEXT("Id : %s, Password : %s"), *IdString, *PasswordString);
		
		UTGameInstance* GI = Cast<UTGameInstance>(GetGameInstance());
		GI->GetTCPModule()->SendLoginPacket(IdString, PasswordString);
	}
}