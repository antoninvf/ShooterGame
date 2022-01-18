// Fill out your copyright notice in the Description page of Project Settings.


#include "SAWidget.h"

#include "SlateOptMacros.h"
#include "Widgets/Notifications/SProgressBar.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SAWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;
	// InArgs._DummyArgument1;
	// InArgs._DummyArgument2;
	// ...

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		  .HAlign(HAlign_Left) // Popř. HAlign_Fill, HAlign_Left, HAlign_Right
		  .VAlign(VAlign_Bottom)
		  .Padding(10)
		[
			SNew(SBox)
			.WidthOverride(300)
			.HeightOverride(80)
			[
				SAssignNew(ProgressBarBlock, SProgressBar)
				.Percent(100)
			]
		]
	];
}

void SAWidget::SetHP(float HP)
{
	ProgressBarBlock->SetPercent((HP / 100));
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
