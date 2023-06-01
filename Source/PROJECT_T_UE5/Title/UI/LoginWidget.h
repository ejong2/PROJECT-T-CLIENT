// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_UE5_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnLoginButtonClicked();

	UFUNCTION()
		void OnChangeCheckBoxValue(bool bIsCheck);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UEditableTextBox* IdInputTextBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UEditableTextBox* PasswordInputTextBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* LoginButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UCheckBox* IsLoginCheckBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ButtonTextBlock;
private:

};
