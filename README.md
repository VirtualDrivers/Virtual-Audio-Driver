> [!WARNING]
> This software is in beta and requires test signing to be enabled.

> [!NOTE]
> Software Developers/Organizations: Looking to implement Virtual speakers/mics into your app? For advanced/custom functionality like named pipes, shared memory buffers (for no-latency audio), direct integration with your existing apps, and more; Contact us for quotes on a custom build! contact@mikethetech.com

# Virtual Audio Driver by MikeTheTech

Welcome to the **Virtual Audio Driver by MikeTheTech**! This project provides two key drivers based on the Windows Driver Kit (WDK):

- **Virtual Audio Driver** – Creates a virtual speaker output device and a virtual microphone input device.

Both features in the driver are suitable for remote desktop sessions, headless configurations, streaming setups, and more. They support Windows 10 and Windows 11, including advanced audio features like Windows Sonic (Spatial Sound), Exclusive Mode, Application Priority, and volume control.

<div align="center">
  <img src="https://github.com/user-attachments/assets/1e833f96-5565-4938-a242-b239074012b0" alt="image">
  <img src="https://github.com/user-attachments/assets/db8c23f3-cf2d-409f-ada8-38d0aa8450a8" width="31%" alt="image">
  <img src="https://github.com/user-attachments/assets/8cf14cc2-4ab0-41ad-a6b2-5a77b004a943" width="31%" alt="image">
  <img src="https://github.com/user-attachments/assets/5f2e23cb-75d3-4557-98ff-7c717f47dcdd" width="31%" alt="image">
</div>

## Overview

A virtual audio driver set consists of:

- **Virtual Audio** ("fake" speaker output)  
  - Essential for headless servers, remote desktop streaming, testing audio in environments without physical speakers, etc.

- **Virtual Microphone** ("fake" mic input)  
  - Ideal for streaming setups, voice chat tests, combining or routing audio internally, or feeding software-generated audio to apps expecting a microphone input.

By installing these drivers, you can process or forward audio without physical hardware present, making them incredibly useful for various development, testing, and media production scenarios.

---

## Key Features

| Feature                                      | Virtual Speaker                                                                                                                                                                          | Virtual Microphone                                                                                                                              |
|----------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| **Emulated Device**                          | Emulates a speaker device recognized by Windows.                                                                                                                                         | Emulates a microphone device recognized by Windows.                                                                                             |
| **Supported Audio Formats**                  | **8-bit, 8000 Hz** (lowest quality) up to **32-bit, 192,000 Hz** (studio quality). This includes various presets such as Telephone Quality (8-bit, 11025 Hz) and DVD/Studio Quality (16/24/32-bit, up to 192 kHz). | **16-bit 44,100 Hz**, **16-bit 48,000 Hz**, **24-bit 96,000 Hz**, **24-bit 192,000 Hz**, **32-bit 48,000 Hz** (for testing or specialized scenarios). |
| **Spatial Sound Support** (Speaker Only)     | Integrates with Windows Sonic, enabling immersive 3D audio features.                                                                                                                      | Integrated with Audio Enhancements such as Voice Focus and Background Noise Reduction.                                                          |
| **Exclusive Mode and App Priority**          | Applications can claim exclusive control of the device.                                                                                                                                  | Same WDK architecture applies, allowing exclusive access in supported workflows.                                                                 |
| **Volume Level Handling**                    | Handles global and per-application volume changes (Windows mixer).                                                                                                                        | Microphone level adjustments accessible via Windows Sound Settings or audio software.                                                            |
| **High Customizability**                     | Built to be extended with future features and audio enhancements.                                                                                                                         | Allows flexible configuration of sampling rates and bit depths for specialized audio requirements.                                               |

---

## Compatibility

- **OS**: Windows 10 (Build 1903 and above) and Windows 11  
- **Architecture**: x64 (tested); ARM64  

---

## Installation

1. **Enable Test Signing (Optional)**  
   If you have a test-signed driver, you may need to enable test signing mode:
   ```powershell
   bcdedit /set testsigning on
   ```
   *Note: A production-signed driver can skip this step.*

2. **Open Device Manager**
   - Choose **Audio inputs and outputs**, then in the top **Action** menu, choose **Add Legacy Hardware**.
   - Choose **Install the hardware that I manually select from a list (Advanced)**
   - Choose **Sound, video and game controllers**
   - Choose "Have Disk..." and locate the **VirtualAudioDriver.inf**
   - Continue with the installation.

3. **Verify Installation**  
   - Open **Device Manager**.  
   - Check under **Sound, video and game controllers** for “Virtual Audio Driver” (speaker).  
   - Check under **Audio inputs and outputs** for “Virtual Mic Driver” (microphone).

---

## Usage

### Using the Virtual Speaker

1. **Select as Default Device**  
   - Open **Sound Settings** → **Output** → Choose “Virtual Audio Driver” as your default output device.  
   - Or use the **Volume Mixer** to route specific apps to the virtual speaker.

2. **Remote Desktop or Streaming**  
   - When initiating a remote desktop session, the virtual speaker device can appear as a valid playback device.  
   - Streaming or capture apps can detect the virtual speaker for capturing system audio.

3. **Choosing Quality Settings**  
   - In **Sound Settings**, under **Playback Devices**, right-click the “Virtual Audio Driver” and select **Properties** → **Advanced** tab.  
   - Choose from the newly added sample rates and bit depths (ranging from 8-bit, 8000 Hz to 32-bit, 192,000 Hz) to match your desired use case (e.g., “Telephone Quality,” “DVD Quality,” or “Studio Quality”).

4. **Spatial Sound**  
   - In **Sound Settings**, right-click the device, select **Properties** → **Spatial Sound** tab, and enable **Windows Sonic for Headphones** or another supported format.

### Using the Virtual Microphone

1. **Select as Default Recording Device**  
   - Open **Sound Settings** → **Input** → Choose “Virtual Mic Driver” as your default input device.  
   - Alternatively, in the **Volume Mixer** or your specific application’s audio settings, route or select the “Virtual Mic Driver” for input.

2. **Supported Formats**  
   - The Virtual Microphone Driver supports:
     - **16-bit, 44,100 Hz**
     - **16-bit, 48,000 Hz**
     - **24-bit, 96,000 Hz**
     - **24-bit, 192,000 Hz**
     - **32-bit, 48,000 Hz**

3. **Use Cases**  
   - **Voice Chat / Conference Apps**: Emulate or inject audio into Zoom, Teams, Discord, etc.  
   - **Streaming / Broadcasting**: Feed application-generated audio to OBS, XSplit, or other streaming tools.  
   - **Audio Testing**: Confirm that your software or game engine’s microphone-handling logic works without real hardware.

4. **Volume & Level Controls**  
   - Adjust input levels in **Sound Settings** → **Recording** tab.  
   - Per-app mic levels can be configured in certain software or system volume mixers (where supported).

---

## Configuration

- **Exclusive Mode** (Speaker and Mic)  
  By default, shared mode is enabled. For real-time, low-latency usage, open device properties, go to the **Advanced** tab, and uncheck “Allow applications to take exclusive control.”

- **Application Priority**  
  Supported through Windows APIs. To prioritize a specific application for either the speaker or microphone, configure it via Windows advanced sound options or in your audio software.

- **Volume/Level Management**  
  - For the Virtual Speaker, adjust in the main Sound Settings or the Volume Mixer.  
  - For the Virtual Microphone, adjust input levels in the Recording tab of Sound Settings or in your audio software’s device preferences.

---

## Future Plans

- **Advanced Diagnostics**: Logging and debugging tools  
- **New Modes & Additional Formats**: Continued expansion of supported audio qualities.  
- **Additional Features**: Such as Automatic Volume Leveling (AVL), further spatial audio improvements, and custom routing tools.

> This project is maintained and actively improved. We welcome contributions, suggestions, and issue reports!

---

**Thank you for using the Virtual Audio Driver!**  
Feel free to open issues or submit pull requests if you encounter any problems or have ideas to share. Happy audio routing!
