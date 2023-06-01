// Fill out your copyright notice in the Description page of Project Settings.



#include "LoginWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/TextBlock.h"
#include "../../TGameInstance.h"


void ULoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginButtonClicked);
	}

	if (IsLoginCheckBox)
	{
		IsLoginCheckBox->OnCheckStateChanged.AddDynamic(this, &ULoginWidget::OnChangeCheckBoxValue);
	}
}

void ULoginWidget::OnLoginButtonClicked()
{
	if (IdInputTextBox && PasswordInputTextBox && IsLoginCheckBox)
	{
		FText Id = IdInputTextBox->GetText();
		FText Password = PasswordInputTextBox->GetText();

		FString IdString = Id.ToString();
		FString PasswordString = Password.ToString();

		UE_LOG(LogTemp, Warning, TEXT("Id : %s, Password : %s"), *IdString, *PasswordString);

		UTGameInstance* GI = Cast<UTGameInstance>(GetGameInstance());
		GI->GetTCPModule()->SendLoginPacket(IsLoginCheckBox->IsChecked(), IdString, PasswordString);
	}
}

void ULoginWidget::OnChangeCheckBoxValue(bool bIsCheck)
{
	if (bIsCheck)
	{
		ButtonTextBlock->SetText(FText::FromString(TEXT("Login")));
	}
	else
	{
		ButtonTextBlock->SetText(FText::FromString(TEXT("SignUp")));
	}
}
