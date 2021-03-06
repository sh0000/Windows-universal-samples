// Copyright (c) Microsoft. All rights reserved.

#pragma once

#include "Scenario9_CustomPairDevice.g.h"
#include "MainPage.xaml.h"
#include "DisplayHelpers.h"
#include "DeviceWatcherHelper.h"

namespace SDKTemplate
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    [Windows::Foundation::Metadata::WebHostHidden]
    [Windows::UI::Xaml::Data::Bindable]
    public ref class Scenario9 sealed
    {
    public:
        Scenario9();

    protected:
        virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

    private:
        void StartWatcherButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void StopWatcherButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void PairButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void UnpairButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

        void StartWatcher();
        void StopWatcher();

        void ResultsListView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

        void PairingRequestedHandler(Windows::Devices::Enumeration::DeviceInformationCustomPairing^ sender, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs^ args);

        void ShowPairingPanel(Platform::String^ text, Windows::Devices::Enumeration::DevicePairingKinds pairingKind);
        void HidePairingPanel();
        concurrency::task<Platform::String^> GetPinFromUserAsync();
        void CompleteProvidePinTask(Platform::String^ pin = nullptr);
        concurrency::task<bool> GetUserConfirmationAsync(Platform::String^ pin);
        void CompleteConfirmPinTask(bool accept);
        void okButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void yesButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void noButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        
        void OnDeviceListChanged(Windows::Devices::Enumeration::DeviceWatcher^ sender, Platform::String^ id);
        void UpdatePairingButtons();
        Windows::Devices::Enumeration::DevicePairingKinds GetSelectedCeremonies();

        MainPage^ rootPage = MainPage::Current;
        Windows::Foundation::Collections::IObservableVector<DeviceInformationDisplay^>^ resultCollection = ref new Platform::Collections::Vector<DeviceInformationDisplay^>();
        DeviceWatcherHelper^ deviceWatcherHelper;

        concurrency::task_completion_event<Platform::String^> providePinTaskSrc;
        concurrency::task_completion_event<bool> confirmPinTaskSrc;
    };
}
