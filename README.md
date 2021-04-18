# dd-wrt build for d-link dir 853/867/878/882 + 1760/1960/2660/2640
firstly, i want to address the spurious allegation that my build of DD-WRT is somehow in violation of the GPL. i am posting this blurb in advance as it seems he feels threatened.
* i am using **publicly available code with little to no changes to the source. i cloned the SVN and made changes to the build settings. there is very little 'code added' by me. the big difference is my build uses GLIBC and i guess this motivated brainslayer to harass forum leaders to take down my stuff**
* if i really did violate the GPL, then why was i posting on the DD-WRT forum for over 3 years? 
* http://web.archive.org/web/20201111193744/https://forum.dd-wrt.com/phpBB2/viewtopic.php?p=1095476
* https://webcache.googleusercontent.com/search?q=cache:y13CRTPv-IEJ:https*//forum.dd-wrt.com/phpBB2/viewtopic.php%3Fp%3D1095476&client=firefox-b-d&hl=en&gl=ca&gbv=1&sei=iil8YM2ZAsjb-gT2vpewBQ
* using unmodified GNU programs (coreutils, bash, bison, sed, gawk, findutils, etc) with GLIBC in the dd-wrt source tree does not violate GPL. simply add the folders  to src/router, edit the make rules (rules/all.mk rules/generic.mk rules/configs.mk) to include their own build file (rules/<file>.mk) and you can build DD-WRT too. 
*

<p>here's a <strong>GNUBS'D-out System V</strong> (or "linux" if you take uname seriously) <strong>DD-WRT</strong> image with a <strong>native BASH</strong> shell (with <strong>Linux-PAM</strong>, <strong>DNSCRYPT</strong>, <strong>OPENDPI</strong>, <a href="https://github.com/openwrt/openwrt/commit/424a9ae128bd2045cd4bfd6e3229f2529d150a25">BLOGIC's <strong>Hardware NAT for MT7621 devices[/b[</a>, [b]<font color="red">WPA3 Support[/COLOR]</strong>, <strong>ENTWARE</strong>; don't think the first five are in BS' build). tools were built/based on a <strong>NeXTSTEP</strong> derivative with GLIBC.<br />
currently kernel <strong>4.14.229</strong> and DD-WRT <strong>v46390<br />
latest FW [COLOR=blue]SE[/COLOR]</strong> ([[COLOR=blue]special edition[/COLOR]] dedicated to John Crispin, aka blogic):<br />
DIR-882/878/853/867:<br />
<u><strong><a href="https://www.sendspace.com/file/xre67m">factory-to-ddwrt-SE.bin</a></strong>[/u], <u><strong><a href="https://www.sendspace.com/file/e4nomk">dlink-dir882-a1-webflash.bin</a></strong></u><br />
DIR-1760/1960/2660/2640 (ignore the file name, it works for all of these routers):<br />
<strong><u><a href="https://www.sendspace.com/file/gp12hv">factory-to-ddwrt-SE.bin</a></u></strong>, <u><strong><a href="https://www.sendspace.com/file/4wzg1c">dir-2640-a1-webflash.bin</a></p><p><a href="https://www.sendspace.com/file/doyuy1">LOOTBAG*</a></strong></u>, <u><strong><a href="https://www.sendspace.com/file/mxksfk">BINUTILS2.35+GCC10.2</a></strong></u> (dead links for now; i will happily re-upload if there's any demand)<br />
<strong>*</strong> lootbag contains: glibc/bash/coreutils locales+tor0.4.4.6+PHP8.0.1+manpages+GNU Midnight Commander4.8.25+GNUMake4.2+sqlite3.30.1+JAVA (via JamVM)+GRoFF1.22.4+minidlna+VIm8.1(2-2123)+tcl8.6.9+Tk8.6.9+libX11-1.6.7*</p><p>older (mt_wifi) versions[/b] (882/878 ONLY since 1760/1960/2660/2640 were just added yesterday!)<br />
(4.14.219/45770) <a href="https://www.sendspace.com/file/c3mfdx">factory-to-ddwrt.bin</a>, <a href="https://www.sendspace.com/file/h1i7hg">dlink-dir882-a1-webflash.bin</a><br />
(4.14.222/45888) <a href="https://www.sendspace.com/file/dsxn7c">factory-to-ddwrt.bin</a>, <a href="https://www.sendspace.com/file/o8v4kc">dlink-dir882-a1-webflash.bin</a><br />
(4.14.226/46177) <a href="https://www.sendspace.com/file/sflda8">factory-to-ddwrt.bin</a>, <a href="https://www.sendspace.com/file/uqdu7s">dlink-dir882-a1-webflash.bin</a><br />
(4.14.229/46333) 853/867/878/882: <a href="https://www.sendspace.com/file/bv148j">factory-to-ddwrt.bin</a>, <a href="https://www.sendspace.com/file/8fdwtk">dlink-dir882-a1-webflash.bin</a> 1760/1960/2660/2640: <a href="https://www.sendspace.com/file/ew4wb7">factory-to-ddwrt-SE.bin</a>, <a href="https://www.sendspace.com/file/6upt3q">dir-2640-a1-webflash.bin</a></p><p>i have tested both builds numerous times, they are safe. they will not brick your router. i have been making an 882 firmware for years. the 2640/2660/1760/1960 is a recent addition but it is even safer since it has a backup. either way, they dont touch your u-boot (its designated as a read-only partition for both builds) so, at worst, all that will happen is you may need to use recovery mode if something happens (i haven't had a report of this yet). i am soliciting input on the next 'new' target. i am hopeful there is some excitement among SNB users, and i'm hopeful some even have the routers currently supported so i can get some feedback.</p><p><u><strong><font size="7">LAUNDRY LIST/INFO</font></strong></u><br />
[LIST]<br />
<li><strong>[27042021 22:28GMT] (46390++) </strong>i've added asterisk, freeradius and transmission as included programs for the 1760/1960/2660/2640 builds (bigger flash) & opened these codepaths on all builds, so if they're installed on a USB key via entware, it will honour DD-WRT configuration settings on boot.</li><li><strong>[15042021 19:31GMT]</strong> i've added a poll to solicit your input on what should be the next router added. i wouldn't mind adding another router or two, but i want them to be "popular". it the build below is for two boards deployed for 8 models, which only differed in their flash memory type.</li><li><strong>[01122019 22:00GMT]</strong> just an FYI, iwpriv's TxPower command is a PERCENTAGE. i think the best way to tweak txpower is using the manual command. if people could test it out and report back i think all ralink users would be grateful (and help restore this brand's status to "the best"). here is the format</li><br />
the manual command is "iwpriv <radio> set TxPwrManualSet=<input>" where i believe input takes five arguments separated by colons (i.e. <arg1>:<arg2>:<arg3>:<arg4>:<arg5>) where each arg is TWO digits (i.e. 14 character string in TOTAL) and takes the following arguments:</p><p><blockquote><br />
<arg1> (manual mode on or off): 00 (manual mode off), or 01 (manual mode on)<br />
<arg2> (band width): 00 (CCK), 01 (OFDM), 02 (HT), 03 (VHT)<br />
<arg3> (frequency, only 20 or 40 for HT): 20 (MHz), 40 (MHz), 80 (MHz, mode 03 only), 160 (MHz, mode 03 only)<br />
<arg4> (manual power rate):<br />
for CCK (00): 0: 1 Mbps ; 1: 2 Mbps; 2: 5 Mbps; 3: 11 Mbps<br />
for OFDM (01): 0: 6 Mbps ; 1: 9 Mbps; 2: 12 Mbps; 3: 18 Mbps; 4: 24 Mbps; 5: 36 Mbps; 6: 48 Mbps; 7: 54 Mbps<br />
for HT20/HT40 (02): HT20: MCS 0 ~ 7; HT40: MCS 0 ~ 8<br />
for VHT20/VHT40/VHT80/VHT160 (03): MCS - 0 ~ 9 for VHT20 ; MCS - 0 for VHT40/VHT80/VHT160<br />
<arg5>: actual value for power (in dB, i think).<br />
-----------------------------------------------------------------------------<br />
SetTxPwrManualCtrl: Set wrong parameters<br />
CCK (0) only supports rate setting: 0 ~ 3 and no supports different BW<br />
OFDM (1) only supports rate setting: 0 ~ 7 and no supports different BW<br />
HT20 (2) only supports rate setting: MCS 0 ~ 7<br />
HT40 (2) only supports rate setting: MCS 0 ~ 8<br />
VHT20 (3) only supports rate setting: 0 ~ 9<br />
VHT40 (3) only supports rate setting: 0<br />
-----------------------------------------------------------------------------<br />
[/quote]<br />
<li><u><strong>entware/using the SES/WPS buttons</strong></u></li><li>the SES (left) button now disables the 2.4G radio, and the WPS (right) button disables the 5G radio. enjoy this fully-functional killer firmware. so good that people are trying to create false rumours about being unable to flash lol.</li><li>i symlinked /usr/local/ to /opt/. so if you mount a usb drive on /opt/, it should have its contents appear in /usr/local. i find this highly desirable. also, enjoy the binutils/gcc suite for this platform. i have tested it and it can compile perl from source. must be pretty, pretty good <img alt=";)" src="/images/emoticons/emoticon-wink.png" /></li><li>to use <u><strong>ENTWARE</strong></u>, do the following:</li><blockquote><br />
mkdir /mnt/main #make main mount point directory<br />
mount /dev/sda1 /mnt/main #mount USB drive to main mount directory<br />
opt-opkg-upd.sh #run the opkg/entware installer script<br />
</blockquote><br />
you now have opkg, and can install packages willy-nilly (tested myself! ENJOY! THIS IS WAY BETTER THAN I ANTICIPATED)<br />
<li><u><strong>additional information about RT2880 (MT7615x2) configuration/manipulation</strong></u></li>[LIST]<br />
<li>each radio now uses one configuration file (i.e. CONFIG_MULTI_PROFILE=n produces AC3467 at 5GHz)</li><li>VAPs can have distinct wireless channels from the main ssid. To set them, use wl{0,1}_channel=ssid1chan;vap1chan;vap2chan;vap3chan;...;vapNchan where the ordering of the N VAPs' channels (not sure if the limit N is 4, 8 or 16 different channels for VAPS on a single radio) should correspond to the order they are listed in the DD-WRT interface (or nvram settings). I think it's possible to have more VAPs than distinct channels for the respective radio. This feature should really let the mt7615 shine (deal with the reboots. don't create VAPs willy nilly and expect it in 10 seconds k, sometimes it takes 25-30seconds more)</li><li>users can instantiate the "wl{0,1}_dbdc={0,1}" nvram variable to enable DBDC mode for whichever radio. AC3467 is currently only possible without DBDC mode from my cursory assessment. still a work in progress.</li><li><strong>PRO TIP #1:</strong> switching from BS' to my build, or vice-versa, CAN (but SHOULD not [from my experience flashing back and forth for debugging purposes]) corrupt your nvram because we use different NVRAM drivers. BACK UP your settings and restore them after first-boot.</li>[/list]<br />
<li><u><strong> additional information about SNMPD </strong></u></li>[LIST]<br />
<li>snmpd now linked to openssl and supports many more encryption types compared to before.</li><li>snmpd_conf is now leveraged by services. you can include additional arguments you'd like in snmpd.conf using this nvram variable, which is present in the httpd GUI when enabling the service. enabling encryption requires multiple lines, which can be entered as follows (<strong><a href="https://wiki.archlinux.org/index.php/snmpd">thx ArchWiki</a></strong>)</li>[quote]<br />
<nvram set snmpd_conf="rouser *desired username for snmp crypto*<hit enter><br />
createUser *desired username for snmp crypto* SHA *desired SHA password* AES *desired AES password*"<hit enter><br />
</blockquote><br />
[/list]<br />
<li><u><strong>supported languages</strong></u> are (as of 35771): traditional chinese, german, hungarian, italian, latvian, polish, russian, portuguese, and english.</li><li><strong> setuserpasswd/httpd's passwd change mechanism uses crypt_r, where i generate the (necessary) 2-byte salt via arc4random_buf--<u>i.e., it is not generated by PAM, but is "PAM-esque". if you want a "pam password", use the "passwd" utility via sshd/telnet</u></strong></li>[/list]<br />
----<br />
[LIST]<br />
<li><u><strong>What's Different in your version of DD-WRT compared to the rest?</strong></u></li><li>[u]<strong>Why should I use this version of DD-WRT as opposed to others (assuming availability)?</strong></u></li>[LIST]<br />
<li>first and foremost: [b]gLIBC 2.33</b>.</li><li>due to the character limit, i will defer people to the larger post on the D-LINK forums that provides a bit <a href="http://forums.dlink.com/index.php?topic=76161.0">[COLOR=rgb(44, 130, 201)" target="_blank">more information</font></a> about my motivations for making this firmware.</li>[/list]<br />
[/list]</p><p>* "IT'S THE GLOBAL ECKANAMY" (Mitt Romney) <cue gesture:><br />
<a href="https://thumb9.shutterstock.com/display_pic_with_logo/401095/154882448/stock-photo-business-man-looks-exasperated-horizontal-154882448.jpg" target="_blank"><img src="https://thumb9.shutterstock.com/display_pic_with_logo/401095/154882448/stock-photo-business-man-looks-exasperated-horizontal-154882448.jpg" alt="https://thumb9.shutterstock.com/display_pic_with_logo/401095/154882448/stock-photo-business-man-looks-exasperated-horizontal-154882448.jpg" border="0" />[/url]</p>
