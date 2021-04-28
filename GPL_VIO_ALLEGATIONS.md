firstly, i want to address the spurious allegation that my build of DD-WRT is somehow in violation of the GPL. i am posting this blurb in advance as it seems he feels threatened.
* i am using **publicly available code with little to no changes to the source. i cloned the SVN and made changes to the build settings. there is very little 'code added' by me. the big difference is my build uses GLIBC and i guess this motivated brainslayer to harass forum leaders to take down my stuff**
* if i really did violate the GPL, then why was i posting on the DD-WRT forum for over 3 years? 
* http://web.archive.org/web/20201111193744/https://forum.dd-wrt.com/phpBB2/viewtopic.php?p=1095476
* https://webcache.googleusercontent.com/search?q=cache:y13CRTPv-IEJ:https*//forum.dd-wrt.com/phpBB2/viewtopic.php%3Fp%3D1095476&client=firefox-b-d&hl=en&gl=ca&gbv=1&sei=iil8YM2ZAsjb-gT2vpewBQ
* using unmodified GNU programs (coreutils, bash, bison, sed, gawk, findutils, etc) with GLIBC in the dd-wrt source tree does not violate GPL. simply add the folders  to src/router, edit the make rules (rules/all.mk rules/generic.mk rules/configs.mk) to include their own build file (rules/<file>.mk) and you can build DD-WRT too. 
* the wireless driver is available at https://github.com/hanwckf/rt-n56u/tree/master/trunk/proprietary/rt_wifi/rtpci/5.0.4.0

in short, there is **NO GPL VIOLATION,  NOR SHOULD ANY USER OF THIS FIRMWARE EXPECT SUPPORT FROM DD-WRT MAINTAINERS. I THOUGHT THIS WAS CLEAR, BUT I AM BEING EXPLICIT.**
