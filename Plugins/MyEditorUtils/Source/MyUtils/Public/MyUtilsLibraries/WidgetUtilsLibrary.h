﻿// Copyright (c) Yevhenii Selivanov

#pragma once

#include "Components/Widget.h"

class UUserWidget;

/**
 * The common functions library for widgets.
 * Is not blueprint accessible since is expensive.
 */
class MYUTILS_API FWidgetUtilsLibrary
{
public:
	/** Return the parent widget of a specific class in the widget tree hierarchy. */
	template <typename T>
	static FORCEINLINE T* GetParentWidgetOfClass(const UUserWidget* ChildWidget) { return Cast<T>(GetParentWidgetOfClass(ChildWidget, T::StaticClass())); }
	static UUserWidget* GetParentWidgetOfClass(const UUserWidget* InWidget, TSubclassOf<UUserWidget> ParentWidgetClass);

	/** Returns first widget found by specified class iterating all widget objects. */
	template <typename T>
	static FORCEINLINE T* FindWidgetOfClass(UObject* WorldContextObject) { return Cast<T>(FindWidgetOfClass(WorldContextObject, T::StaticClass())); }
	static UUserWidget* FindWidgetOfClass(UObject* WorldContextObject, TSubclassOf<UUserWidget> ParentWidgetClass);

	/** Returns the slate widget from UMG widget.
	* As an example, it returns SCheckbox slate widget from UCheckBox widget. */
	template <typename T>
	static FORCEINLINE TSharedPtr<T> GetSlateWidget(const UWidget* ForWidget) { return ForWidget ? StaticCastSharedPtr<T>(ForWidget->GetCachedWidget()) : nullptr; }

	/** Completely destroys specified widget.
	 * Is useful for MGF-modules unloading in runtime.
	 * In most gameplay cases it should not be used, since it's expensive: prefer collapse widget instead. */
	static void DestroyWidget(UUserWidget& ParentWidget);
};
