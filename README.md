# CastleFeeder
This is a feeding device for mice

## Front 
![](https://lh7-us.googleusercontent.com/vSr7VCN0qVtdDB44vWetYbDK7vRgvD00LOMCKkTSQs4mqXMZ4WOpMdLgZp4YNw0FbxEI_BbUFCne0pqgDcHBS-8voEMCSu5zEk2-AbTlN2Jwou1Tpx4oqyLpQKtUMZkiTxR59jy5D0iI-Lqz9oddcdA)

## Back  ![](https://lh7-us.googleusercontent.com/CHlP_DLuCl7HKqEwtJ72F7hrdRNvUUlpC4PzViTq-X-as9BEmjUmHqaIItK2yMCSC8bH6Basc2wzaU_pgtALT2ZpurEHigiQ7rxscdhDUYxjnV5JQI-WSHo5CiEHGq9JxTrHOfnG5CkvM1bl4iovj-A)

  

## Setting up your castle feeder:

  
![](https://lh7-us.googleusercontent.com/UFu_ip_bKuPJxnfXzTFwt_Oapdgl-trS5rEYMW0DFjI-PUKjQdpWF1n-9NSOEbPv0f7LSmzftuXlq3giRpTQbMK_reoLVttl9Mj9mTLKRdWtM6C5c_COYrcq4GgKi5rDp-9fhdBeqxE1lWrlttsjEek)  

To begin using the castle feeder, you will need to set your desired experimental parameters. To change parameters press the blue button while on the settings screen. This will put the device into edit mode. In edit mode the blue button is used to navigate between the different settings. On mode, device number, and seconds open, the red button is used to change the parameters. Mode will cycle between FR1 and Free, device number ranges from **0 to 19**, and seconds open ranges from **10 to 120**. The seconds open setting only applies to the FR1 mode, free feed leaves the device open at all times, except during shake. When editing open position and closed potion, the green and red buttons are used to decrease or increase the values. Once your parameters are set, you can press the red button to start.

  
  
  

## Running Castle Feeder:

  

When you have set your desired experimental parameters, press the red button to start the device. A mouse will run across the screen and it will display “Running!” at the top. This screen will display the **mode, the device number, total left touches, total right touches, and total feed measurements**. Feed is measured when the mouse touched the bars in the front.

  

### FR1 task:

  

The FR1 task allows the mouse to control its feeding time. The mouse can access the food in the tumbler by touching the brass touch sensor on the left side of the device (left when looking at the device from the mouse's perspective). The right touch sensor does nothing, but touches are still recorded. The amount of time that the device is open is set on the settings menu. **60 seconds** is the open time used most often.

  
  

Placing the Castle Feeder in a cage. The Castle Feeder was designed for AllenTown Nex Gen 500 cages. Place the device at the front of the cage with the electronics facing away from the mouse. The lid will close and the cage can be placed on the rack with the device inside.

![](https://lh7-us.googleusercontent.com/dmyEzzLUFzQ8dOxM5gXccSpOoxSmiTZuiEWa-95ewH3O3lb5aMWRmBwUSwoD3VkcOeP4zOnaT5ExnaF_N2Z_vcGmw1Xpy9dp5MJgUUaaaEVaJFFTpjDImffh_6VoUsAd9DmwQUwpX45uxbphVV9zCUA)![](https://lh7-us.googleusercontent.com/ig4Q0qfnyjPcC8Oorf19aT62hAFr9A40Dc8K5q79RjznV1Ey9J6Xf3CoTEZd84nH2m4S5GyouF5Ms--FUn6d_rdzvzgHFIAkFYNvuuJHbfAcdeJfx0RK8fY_kTTQTxf5M-HJ-zpzOEMgxej6l5kX2UE)![](https://lh7-us.googleusercontent.com/WqgRPIz74PzURq2qbBGj8H8kYZvA3rvaeZGmNhwdTnyUDbLtUWAyy-oGpLKYT2z7Rnh_mafaagRp93YDFrMEbJmPw3HzEd1DtJe059-RuZRbyC-aqsFpU0v6o0V5TVd7E5nzRV1SM4RmQKHV_81uNQY)

### Charging Castle feeder:

When the battery level on the device drops **below 3.6**, plug a micro usb cable into the port on the adafruit board on the left side of the device.


![](https://lh7-us.googleusercontent.com/2HGKczvR-OhmkWS5Dx3mGRllV4TboDORGz4m02ZwNSWqNbQXxfrVwOpG3NMHGHFfUAsHRM4DMTUJhERAHLwwIOR_o3a-BrVfYmeRfytJaKOHa8BxRtaA1I5i0K7e8rLkSgQF7CReChfsA9WJ2UWplbE)

  

### SD card data:

To remove the SD card from the device, just push it into the holder and it will pop out, Once you have uploaded you data to a computer, you will see an excel file titled something like `CASTLE_002_122923_00_` This filename includes the date, device number, and the file number. After opening the file you will see this:

![](https://lh7-us.googleusercontent.com/0-oxV2rHU3RiVQPm-e08Uw-JVEMbyPkvJgFFG5m9qSNHb11nKNiobCEl-d2m6jXPMuk01YiTsJhSjJpTJQzYMBxLmEKX3T-aStNBMaSo5LJxQSmUnmXRB6xMkP2yJSdWMnPDOvymFx-ytLvW63O9zho)

The file include the date and time, temperature in the cage, seconds since the device was started, battery voltage, number of left pokes, duration of the pokes, number of right pokes, duration of those pokes, number of times the animal ate, and the mode the device was set too.

  

### Tips and Tricks:

  

Using **60% high fat diet** in the device can cause the pellets to stick together, preventing the mouse from accessing the food. While the shake setting on the device helps a little bit, occasionally you will have to mix the food up. This can be done by shaking the device or opening the back door and mixing up the food. Also, not overfilling the device and using smaller pieces help to prevent sticking inside the tumbler.

The best open position is when the feeding side of the tumbler is just past the blocking wall.

![](https://lh7-us.googleusercontent.com/D0hMUw6oZBFsbzLEoE0TVZi2tyYV9gf0kltSoccSkc1W2yaScRMTLLNQX8MNsHERkWPXCl-70cUqbDs8bxqBtw9DsxpXDyEUGbHkp_yTrgIEKfrNcGf9RyURJAMRsNANtesb3Gy9J6ytUHKKwFmT1ho)

The best closed position is when the stoper located above the door has just touched the top of the dividing wall.

