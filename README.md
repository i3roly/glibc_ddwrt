# dd-wrt build for d-link dir 867/878/882/1935 + 1760/1960/2660/2640 + 3060/3040

(see GPL_VIO_ALLEGATIONS.MD first please)
----------
here's a <b>GNUBS'D-out System V</b> (or "linux" if you take uname seriously) <b>DD-WRT <span style="color:blue">SE</span></b> ([<span style="color:blue">special edition</span>] dedicated to John Crispin, aka blogic) image with a <b>native BASH</b> shell (with <b>Linux-PAM</b>, <b>DNSCRYPT</b>, <b>OPENDPI</b>, <a href="https://github.com/openwrt/openwrt/commit/424a9ae128bd2045cd4bfd6e3229f2529d150a25">BLOGIC's <b>Hardware NAT for MT7621 devices</b></a>, <b><span style="color:red">WPA3 Support</span></b>, <b>ENTWARE</b>; don't think the first five are in BS' build). tools were built/based on a <b>NeXTSTEP</b> derivative with GLIBC.

this readme is updated periodically. thus the DD-WRT and kernel versions may be far newer than what is given below. this document serves as a guide for using the firmware.

latest FW :
-------------
currently kernel <b>4.14.302</b> and DD-WRT <b>v51063</b>

DIR-882/878/867/1935: use the dir-882 firmware

DIR-1760/1960/2660/2640: use the dir-2640 firmware

DIR-3040/3060: use the dir-3040 firmware

<b>*</b> lootbag contains: 
<ul>
<li> manpages  </li>
 <li>GNU Midnight Commander</li>
<li> tor </li>
<li> make  </li>
<li> sqlite </li>
<li> java (JamVM) </li>
<li> GroFF (for manpages) </li>
<li> VIm8.1(2-2123) </li>
<li> minidlna  </li>
<li> SOFTETHER  </li>
<li> tcl/tk 8.6.9 </li>
<li> libX11-1.6.7*</li>
<li> and a bunch of other shit </li>
</ul>

i have tested both builds numerous times, they are safe. they will not brick your router. i have been making an 882 firmware for years. the 2640/2660/1760/1960/3040/3060 are recent additions but it are even safer since they have a backup. 
either way, they dont touch your u-boot (its designated as a read-only partition for both builds) so, at worst, all that will happen is you may need to use recovery mode if something happens (i haven't had a report of this yet). 


HOW TO FLASH TO/FROM STOCK FIRMWARE
-----------
<ul>
<li> download the "factory-to-ddwrt-SE.bin" for your respective model (see above)
<li> turn your router off. 
<li> hold the reset button and turn your router on.
<li> let go of the reset button once you see the power light flashing.
<li> plug in an ethernet cable and assign your device the following properties:
<ul>
<li> static IP: 192.168.0.101
<li> netmask: 255.255.255.0
<li> router IP: 192.168.0.1
</ul>
<li> wait a few seconds after you apply these settings.
<li> go to http://192.168.0.1
<li> load the appropriate factory-to-ddwrt-SE.bin file and wait.
<li> all of these steps apply to restore the stock firmware from dd-wrt.
<li> we have provided the decrypted versions of supported devices' firmware in the stock_fw to make it easy for people to go back and forth.
<li> enjoy
</ul>

many thanks to @0xricksanchez for his proof of concept that allows people to use the decrypted firmware to go back and forth (otherwise it's a nuisance).

LAUNDRY LIST/INFO
-----------
<ul>
<li><b>WPA2-MSCHAPv2 in REPEATER MODE should be WORKING as of 51011 .</b></li>
</ul>

USAGE
--------------
<ul>
 <li><b>SETTING TX POWER MANUALLY:</b>
  
the manual command is "iwpriv &lt;radio&gt; set TxPwrManualSet=&lt;input&gt;" where i believe input takes five arguments separated by colons (i.e. &lt;arg1&gt;:&lt;arg2&gt;:&lt;arg3&gt;:&lt;arg4&gt;:&lt;arg5&gt;) where each arg is TWO digits (i.e. 14 character string in TOTAL) and takes the following arguments:

<blockquote>
&lt;arg1&gt; (manual mode on or off): 00 (manual mode off), or 01 (manual mode on)
&lt;arg2&gt; (band width): 00 (CCK), 01 (OFDM), 02 (HT), 03 (VHT)
&lt;arg3&gt; (frequency, only 20 or 40 for HT): 20 (MHz), 40 (MHz), 80 (MHz, mode 03 only), 160 (MHz, mode 03 only)
&lt;arg4&gt; (manual power rate):
for CCK (00): 0: 1 Mbps ; 1: 2 Mbps; 2: 5 Mbps; 3: 11 Mbps
for OFDM (01): 0: 6 Mbps ; 1: 9 Mbps; 2: 12 Mbps; 3: 18 Mbps; 4: 24 Mbps; 5: 36 Mbps; 6: 48 Mbps; 7: 54 Mbps
for HT20/HT40 (02): HT20: MCS 0 ~ 7; HT40: MCS 0 ~ 8
for VHT20/VHT40/VHT80/VHT160 (03): MCS - 0 ~ 9 for VHT20 ; MCS - 0 for VHT40/VHT80/VHT160
&lt;arg5&gt;: actual value for power (in dB, i think).
-----------------------------------------------------------------------------
SetTxPwrManualCtrl: Set wrong parameters
CCK (0) only supports rate setting: 0 ~ 3 and no supports different BW
OFDM (1) only supports rate setting: 0 ~ 7 and no supports different BW
HT20 (2) only supports rate setting: MCS 0 ~ 7
HT40 (2) only supports rate setting: MCS 0 ~ 8
VHT20 (3) only supports rate setting: 0 ~ 9
VHT40 (3) only supports rate setting: 0
-----------------------------------------------------------------------------
</blockquote>
</li>

<li><u><b>entware/using the SES/WPS buttons</b></u>
</li><li>the SES (left) button now disables the 2.4G radio, and the WPS (right) button disables the 5G radio. enjoy this fully-functional killer firmware. so good that people are trying to create false rumours about being unable to flash lol.
</li><li>i symlinked /usr/local/ to /opt/. so if you mount a usb drive on /opt/, it should have its contents appear in /usr/local. i find this highly desirable. also, enjoy the binutils/gcc suite for this platform. i have tested it and it can compile perl from source. must be pretty, pretty good ;)
</li><li>to use <u><b>ENTWARE</b></u>, do the following:
<blockquote>
mkdir /mnt/main #make main mount point directory
mount /dev/sda1 /mnt/main #mount USB drive to main mount directory
opt-opkg-upd.sh #run the opkg/entware installer script
</blockquote>
you now have opkg, and can install packages willy-nilly (tested myself! ENJOY! THIS IS WAY BETTER THAN I ANTICIPATED)
</li><li><u><b>additional information about RT2880 (MT7615x2) configuration/manipulation</b></u>
<ul>
<li> each radio now uses one configuration file (i.e. CONFIG_MULTI_PROFILE=n produces AC3467 at 5GHz)
</li><li>VAPs can have distinct wireless channels from the main ssid. To set them, use wl{0,1}_channel=ssid1chan;vap1chan;vap2chan;vap3chan;...;vapNchan where the ordering of the N VAPs' channels (not sure if the limit N is 4, 8 or 16 different channels for VAPS on a single radio) should correspond to the order they are listed in the DD-WRT interface (or nvram settings). I think it's possible to have more VAPs than distinct channels for the respective radio. This feature should really let the mt7615 shine (deal with the reboots. don't create VAPs willy nilly and expect it in 10 seconds k, sometimes it takes 25-30seconds more)
</li><li><b>PRO TIP #1:</b> switching from BS' to my build, or vice-versa, CAN (but SHOULD not &#91;from my experience flashing back and forth for debugging purposes&#93;) corrupt your nvram because we use different NVRAM drivers. BACK UP your settings and restore them after first-boot.
</li></ul>
</li><li><u><b> additional information about SNMPD </b></u>
<ul>
<li>snmpd now linked to openssl and supports many more encryption types compared to before.
</li><li>snmpd_conf is now leveraged by services. you can include additional arguments you'd like in snmpd.conf using this nvram variable, which is present in the httpd GUI when enabling the service. enabling encryption requires multiple lines, which can be entered as follows (<b><a href="https://wiki.archlinux.org/index.php/snmpd">thx ArchWiki</a></b>)
<blockquote>
&lt;nvram set snmpd_conf="rouser *desired username for snmp crypto*&lt;hit enter&gt;
createUser *desired username for snmp crypto* SHA *desired SHA password* AES *desired AES password*"&lt;hit enter&gt;
</blockquote>
</li></ul>
</li><li><u><b>supported languages</b></u> are (as of 35771): traditional chinese, german, hungarian, italian, latvian, polish, russian, portuguese, and english.
</li><li><b> setuserpasswd/httpd's passwd change mechanism uses crypt_r, where i generate the (necessary) 2-byte salt via arc4random_buf--<u>i.e., it is not generated by PAM, but is "PAM-esque". if you want a "pam password", use the "passwd" utility via sshd/telnet</u></b>
</li></ul>
----
<ul>
</ul>


What distinguishes this DD-WRT build?
----
<ul>
 <li><u><b>Why should I use this version of DD-WRT as opposed to others (assuming availability)?</b></u>
<ul>
<li>first and foremost: <b>gLIBC 2.33</b>.
</li>
<li> who cares. i am not going to give reasons for my motivations and why i continue to do this. i did that for three years. i'm over it now. just be greedy and consume.
 <ul>
  <li> if you don't want to try it, don't. </li>
  <li> if you want the subpar stock firmware that has good wifi performance: keep it. </li>
  <li> if you want terrible openwrt or DD-WRT with that stinky faeces they call the mt76 driver: use it.
   <ul><li>no one is forcing you to try this build, but there must be a reason the DD-WRT maintainer is exerting so much energy trying to bury this build. 
    <ul><li>maybe he has shares in mediatek too.</li></ul>
   </ul>
 </ul>
</li></ul>
</li></ul>

* "IT'S THE GLOBAL ECKANAMY" (Mitt Romney) &lt;cue gesture:&gt;
<img src="https://thumb9.shutterstock.com/display_pic_with_logo/401095/154882448/stock-photo-business-man-looks-exasperated-horizontal-154882448.jpg" />
