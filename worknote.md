
google keep
    sudo apt install gitk
    gitk --all

    git add -u 則可以僅將「更新」或「刪除」的檔案變更寫入到「索引檔」中

    直接在檔案系統中刪除一個檔案，這只是從「工作目錄」中刪除而已，並沒有更新到索引檔
    git rm filename 的時候，除了更新索引檔之外，連工作目錄下的檔案也會一併被刪除
    git rm --cached a.txt 你只想刪除索引檔中的該檔，又要保留工作目錄下的實體檔案

    clean working dir
    git clean -n  = see what will be cleaned
    git clean -f -d = force to clean dir and files

    show HEAD
    git rev-parse HEAD
    git show-ref --head  <<remember this will do
    cat .git/HEAD
            ref: refs/heads/terry
    cat .git/refs/heads/terry

    git branch -a
    git remote -v
    git fetch

    lshw


    set env variable permanant
    $ vi ~/.bash_proflle
    export PATH=${PATH}:${HOME}/bin

    set -x

    $ type set
    set is a special shell builtin
    Since set is a shell builtin, it is documented in the documentation of your shell.

    sudo apt install autoconf

    find . -name config.cache | sed -n 3p
        under newlib dir / how to vim that file directly? 
        vim can't edit the input pipe file name directly
    vim $(find . -name config.cache | sed -n 3p)
        can do in this way

    grep xxx -r * | nl

    94  /home/cm/work/newlib-nano-1.0_/libgloss/arm/syscalls.c:_sbrk (int incr)        
    grep _sbrk -riw ~/work/newlib-nano-1.0_/ | sed -n 94p | awk 'BEGIN {FS=":"} {print $1}'
    /home/cm/work/newlib-nano-1.0_/libgloss/arm/syscalls.c


    build
    reent , stdio
    cm@cm-X555LD:~/work/newlib-nano-1.0_/libgloss/libnosys$ gcc -c *.c -I../../newlib/libc/include/sys -I../../newlib/libc/include/

    ld *.o ../reent/*.o ../../../libgloss/libnosys/*.o -o a.out


    ubuntu chinese language support


    ssh-keygen

    使用 dd 來建立一個大檔案：
    dd if=/dev/zero of=/root/dd_10mb_file bs=1M count=10

    sudo apt install screen

    gcc -I newlib/libc/include -I newlib/libc/machine/arm -D__ARM_ARCH_6M__ -M -E newlib/libc/sys/arm/syscalls.c 
    syscalls.o: newlib/libc/sys/arm/syscalls.c /usr/include/stdc-predef.h \
     newlib/libc/include/_ansi.h newlib/libc/include/newlib.h \
     newlib/libc/include/sys/config.h newlib/libc/include/machine/ieeefp.h \
     newlib/libc/include/sys/features.h newlib/libc/include/_newlib_version.h \
     newlib/libc/include/sys/types.h newlib/libc/include/sys/cdefs.h \
     newlib/libc/include/machine/_default_types.h \
     /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h \

    cm@cm-X555LD:~/work/newlib-cygwin2$ gcc -I newlib/libc/include -I newlib/libc/machine/arm -dM -E -P newlib/libc/sys/arm/syscalls.c
    #define __GNUCLIKE_BUILTIN_NEXT_ARG 1
    #define __SSP_STRONG__ 3
    #define S_ISCHR(m) (((m)&_IFMT) == _IFCHR)
    #define __strftimelike(fmtarg,firstvararg) __attribute__((__format__ (__strftime__, fmtarg, firstvararg)))
    #define __DBL_MIN_EXP__ (-1021)
    #define _SC_XOPEN_UNIX 105
    #define _NOINLINE_STATIC _NOINLINE static
    #define F_UNLKSYS 4
    #define EMULTIHOP 74
    #define __IMPORT 
    #define _QUAD_LOWWORD 0
    #define O_NOCTTY _FNOCTTY
    #define __unused __attribute__((__unused__))
    #define FMARK _FMARK

    -MM Like -M but do not mention header files that are found in system header directories
    -gcc -M -MM a.c
    a.o: a.c b.h



    backup files
    (worked!!) find . -name '*.mp3' -type f -exec cp --parent {} ../test/ \;

    At the Linux command line, I'd like to copy a (very large) set of .txt files from one directory (and its subdirectories) to another.
    I need the directory structure to stay intact, and I need to ignore files except those ending in .txt

    cd /top/level/to/copy
    find . -name '*.txt' | cpio -pdm /path/to/destdir
    (-updm for overwrite destination content.)


    附近的(加油站/醫院/警察局/XXX
    提醒我（明天/後天/X月X日/下周X）（X點X分）在（地名）有（何事情）
    計時XX秒/XX分鐘/XX小時
    設定X點X分的鬧鐘  設定X小時/X分鐘後的鬧鐘
    翻譯(英文單詞)
    一萬日元
    對著Google喊出算式，他就會幫你開始自動計算，還不如用Google Now喊「計算機」
    打開（完整軟體名稱


eclipse
    install jre /usr/java/jre1.8.0_121
    sudo ./openocd -f ../scripts/interface/nulink.cfg -f ../scripts/target/numicroM4.cfg
    gdb server
        load_image filename address ['bin'|'ihex'|'elf'|'s19'] [min_address] [max_length]


teamviewer
    sudo apt-get install libjpeg62
    wget http://download.teamviewer.com/download/teamviewer_i386.deb
    sudo dpkg -i --force-depends teamviewer_i386.deb
    sudo apt-get install -f
    teamviewer --daemon start
    teamviewer

>>sublime
    在Sublime中，安装插件之前我们需要添加Package Control,打开View——Show Console，输入以下命令：

    import urllib.request,os,hashlib; h = '2915d1851351e5ee549c20394736b442' + '8bc59f460fa1548d1514676163dafc88'; pf = 'Package Control.sublime-package'; ipp = sublime.installed_packages_path(); urllib.request.install_opener( urllib.request.build_opener( urllib.request.ProxyHandler()) ); by = urllib.request.urlopen( 'http://packagecontrol.io/' + pf.replace(' ', '%20')).read(); dh = hashlib.sha256(by).hexdigest(); print('Error validating download (got %s instead of %s), please try manual install' % (dh, h)) if dh != h else open(os.path.join( ipp, pf), 'wb' ).write(by)

    markdown shortcut
    - tab , shift tab
    - This is [an example][id] reference-style link.
      [id]: http://www.kimo.com/  "Optional Title Here"
    - [myhtm](http://127.0.0.1/arm.html)
        C:\inetpub\wwwroot
    - #![img](htm\a.JPG)
    
    MarkdownEditing
    command + option + k 插入链接
    command + shift + k 插入图片
        ![img](htm/a.JPG)

    安装OmniMarkupPreviewer
    Command +Option +O: 在浏览器中预览
    Command+Option+X: 导出HTML
    Ctrl+Alt+C: HTML标记拷贝至剪贴板



>>ubuntu 16.04
    1. package 'vim'has no installation candidate
        sudo apt-get update 
        sudo apt-get upgrade
    2. brightness-controller
    3. install vim
        sudo apt-get update
        sudo apt-get install vim
    4. add environment PATH
        /etc/enviroment 
        source /etc/environment

    ctags
    在source code的最外層目錄輸入指令
    $ ctags -R *
    vim中輸入以下指令來載入對應的tag
    :set tags=/home/sway/src/tags
    
    lspci -nnk
        Broadcom Corporation BCM43142 802.11b/g/n [14e4:4365] (rev 01)
    sudo apt-get install bcmwl-kernel-source

    sudo apt-get install texi2html
    sudo apt install texlive-binaries     

    gnu arm toolchain
    sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
    sudo apt-get update
    sudo apt-get install gcc-arm-embedded
    sudo apt-get remove gcc-arm-none-eabi

    4  sudo add-apt-repository ppa:apandada1/brightness-controller
    5  sudo apt-get update
    6  sudo apt-get install brightness-controller

   28  sudo app-get exuberant-ctags
   29  sudo apt-get exuberant-ctags
   30  sudo apt-get install exuberant-ctags
   
   sudo apt install indent
   
   install sublime, install jvm, install eclipse CDT

   wireless
        ifconfig -- 用來開啟/關閉介面卡
        iwconfig -- 用設定無線的 SSID, key
        iwlist -- 用來搜尋周圍 AP
        dhcpcd -- 經由 dhcp 得到 ip

        首先，先找出你的無線網卡是哪個名字
        ifconfig -a

        找到介面的名字後，若是沒有打開，就把它打開
        ifconfig wlan0 up

        接著，設定無線網卡的 SSID (在 linux 世界都叫它 ESSID)
        iwconfig wlan0 essid <essid>

        還有設定無線網卡的金鑰
        iwconfig wlan0 key <key>

        最後，設定 ip，若是使用 dhcp，使用指令如下
        dhcpcd wlan0

        指定 ip 則是使用下例指令
        ifconfig wlan0 192.168.1.2
        網路匣道設定
        route add default 192.168.1.1

    install perforce
    perforce linux super username:super, pass:most general

    synergy
    sudo dpkg -i synergy-1.4.18-r2250-Linux-x86_64.deb

>>google chrome
    在網頁上水平捲動	按住 Shift 鍵並滾動滑鼠滾輪
    在目前的分頁中開啟首頁	Alt + Home 鍵
    切換至下一個開啟的分頁	Ctrl + Tab
    關閉目前的分頁	Ctrl + W
    開啟連結並切換至連結網頁	按住 Ctrl + Shift 鍵，然後按一下連結
    在新的背景分頁中開啟連結	按住 Ctrl 鍵，然後按一下連結
    在新分頁中開啟「歷史紀錄」頁面	Ctrl + H 鍵
    在新分頁中開啟「下載」頁面	Ctrl + J 鍵
    停止載入網頁	Esc 鍵

office	
    windows system variable:
    1937 NB, acer travelmate 8481g. 
    close all command windows and reopen to enable the effects
    C:\Program Files\GnuWin32\bin;
    C:\Program Files\GNU Tools ARM Embedded\5.4 2016q3\bin;
    C:\ProgramData\Oracle\Java\javapath;%SystemRoot%\system32;%SystemRoot%;
    %SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;
    c:\Program Files\Microsoft SQL Server\90\Tools\binn\;
    C:\Program Files\Windows Kits\8.1\Windows Performance Toolkit\;
    C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;
    C:\CooCox\CoIDE\gcc\bin;
    C:\CooCox\CoIDE_V2Beta\gcc\bin;
    C:\CooCox\CoIDE_V2Beta\bin;
    C:\Program Files\TortoiseSVN\bin;
    C:\Program Files\TortoiseGit\bin;
    C:\keil\520s\ARM\ARMCC\bin;
    %CDSROOT%\tools\pcb\bin;
    %CDSROOT%\tools\fet\bin;
    %CDSROOT%\tools\specctra\bin;
    %CDSROOT%\tools\PSpice;
    %CDSROOT%\tools\PSpice\Library;
    %CDSROOT%\tools\Capture;
    %CDSROOT%\tools\bin;
    C:\Program Files\Java\jre1.8.0_91\bin

    outlook archive
    C:\Users\CCMA\Documents\Outlook Files

    windows file explorer
    Alt + Up – Switches to the parent folder in the hierarchy
    Alt P – Toggles the Preview pane
    Alt+Enter – Opens Properties for the selected object

    windows command line
    devmgmt.msc
    appwiz.cpl

git:
    git reflog push to remote 時, 是否會跟著走?
    git diff
    
    git reflog (if HEAD is detached, you can find it back)




M480
    <ETMC performance>
    68cycle (4WORDS) x 4 (16WORDS) = 272 cycles
    O0 ETMCPDMA+USBDMA 228 cycle 
        手算 94cycles (11/10新收到 firmware)
    O2 ETMCPDMA 68 -> 37 cycles

    ETMC PDMA 512bytes to SRAM
        68cycle x 512/16 = 2176 cycle

    USBDMA from INTERNAL SRAM to USB BUF 
        512bytes -> 1488 cycles
        1KB -> 2866 cycles
        2KB -> 5582 cycles

    O0   FW:pingpong 50KB EP 3KB     PC: BUF 100KB   RESULT: 3.7MHz traceclk

    
FW release note
    cks.bin 主要有二個值要填
    一個是 ICE_M0.bin 的 file size 4bytes
    另一個是 ICE_M0.bin 的 2 bytes checksum, 用 HxD 開 ICE_M0.bin 選 checksum 16
</ETMC performance>
</M480>


<M2351>
    [compile option]
    arm-none-eabi-gcc -march=armv8-m.base -mthumb -mcmse -g3 -c main.c
    arm-none-eabi-as -march=armv8-m.base -mthumb startup.S -g3 -o startup.o
    arm-none-eabi-ld -Tflash.ld -o output --cmse-implib --out-implib=nsclib.o
        VSS M2351 folder 抓下來的 BSP TZ sample 少了 -mcmse option, _ARM_FEATURE_CMSE=1 
        .gnu.sgstubs放在RAM會 assert.  arm-none-eabi-ld: BFD (GNU Tools for ARM Embedded Processors) 2.26.2.20160923 assertion fail /home/build/work/GCC-5-build/src/binutils/bfd/elf32-arm.c:4185

        .gnu.sgstubs :
        {
            . = ALIGN(4);
            *(.text)
            . = ALIGN(4);
        } >FLASH   

    arm-none-eabi-ld -Tflash.ld -o output 


    NSCBOUND 0x200800[23:0]
    SCRLOCK 0x200804[7:0] 0x5a means unlock
    SCB_NS 0xe002e000  VTOR offset 0x8

    coremark
        M451 (YC's code)
        MDK454 2.17
        MDK514 2.67

        MDK514+GCC5.4
        O2(Time) 2.453
        O3  2.600

    更改 scatter loader , .axf 以及 .bin 都會記錄 execution region 的改變. .bin 會帶 VMA 資料.
    
    void __attribute__ ((section (".FUNCTIONA"))) testTerry(void);

    non-secure project SRAM 可以直接設定 0x30010000?
    ANS- 跑完 Scu config , 0x30010000 才能存取    
    
    [MDK option] --import-cmse-lib-out .\Objects\nsclib.o
    [gnu option] -mcmse     –with-newlib
    
    GCC modify:
        __Vector to __isr_vector
        add __TZ_set_MSP_NS in cmsis_gcc.h
        idau_ref -- mark temporarily
        SCB->VTOR = (uint32_t) &isr_vector;
        
        #if defined ( __GNUC__ )
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wsign-conversion"
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wconversion"
        #pragma GCC diagnostic ignored "-Wunused-parameter"
        #pragma GCC diagnostic ignored "-Wmissing-braces"
        #endif
        
    [eclipse setting]
        project/workspace/global setting of eclipse
        ${cross_prefix}${cross_c}${cross_suffix}        

    <etm divider>
        (M480 also the same address) FPGA for v8m and m23 etm divider and center (0x4000_0230 [31:24] HCLK divider)
</M2351>
        
        
#child
    生日會播放回顧影片
    
    佩佩豬英文教學
    
    雷射照的到對面大樓嗎?
    紙飛機能飛多遠?
    靜坐

    ㄈ方
    ㄉ刀
    ㄊ討
    ㄎ可
    ㄔ吃
    ㄕ杓
    ㄩ淤
    ㄟㄟ阿
    ㄦ兒
     
     
>>Fri會議
    >> 測試和文件相關工作, should be take care by engineer ?
    >> (tu) NuGang totally phased out?  isplink, offline cert testing    
    >> (各 ip 出 pin 對 chip 的影響是 "內部" layout 不好 lay?) sGPIO 為何不要每一根都有 sGPIO 能力? 成本? (sGPIO 設計原意是什麼?)
    ISPTool FW to BSP
    why so many training by HR
    TC8234 nugang board item ignore, nulink gang?      

    (cy0) XOM can'eet set breakpoint    
    If mp version chip is ready, need to support shuttle? (Terry check)
    
    M2351 shuttle version PDID

#Thur會議       
    * make tz printf work, test functions , incorporate with Zale next week
    * Confirm need 2nd? Can mbed compiler support? <- chris will follow up, no clear answer, develop 1st first, but second seems can't avoid
    6596 to 6600 fw upgrade will hang up?

    ##ccli    
    - special part 
        - NUC123SD4SN5 (hank)
        - nuc121 special part number (hank)
    * ycc m2351 which ib should be generate, CCLI M480??
    kprom lock, hw bp of M480 will be disable??
    chlin55 NUCMD TOOL
    TODO
        TC8226 offline download SRAM, sram is 16KB, page size 4KB, current stack use 11.x KB, mbed 3.5KB, if to write serial number need one page buffer and not enough space
        need uninstall while install different version ICPTool
        checkpointer of excel will see in every excel file not only psio
    
    ##ycc
    burn code mode of m2351, solid?
    * 6600a2 how about IAR?
    * composite device IAD
    iar 2nd develop    
    (ycc) mbed 閃退, walter question, outlook <- 之前測是 win10 64bits (self test ok). wright said "VM 簡中企業版 win10 64bits" may has problem
    (ycc) TC8234 driver for MP version 
    (ycc) user manual m2351 
    
    * (yung) nuconsole document
    (yung) jtrace/ulink performance  

    how do eclipse do semihosting? combine with Newlib.
    * (cyyu) eclipse on v8m option with my 2 project, GDB test, eclipse burn bin file directly or elf fromelf to bin file and burn??
    (cyyu) openOCD confidential commands shows to ME10    
    (cyyu) pinconfig auto permutation, ask JC about the algorithm, location first? or don't care?
    (cyyu) clock excel 
    (cyyu) Zale 發現問題點是使用win10 內建的 unzip 軟體去解壓 7-zip 壓縮出來的 .zip file 會有問題, 換成 7-zip 軟體解壓就 ok.    

    ##cctu
    * when is nuc505/nuc472 upload?      
    * all in one
    * secure boot isp m480 need to go with nulink certain version? if we have v2.02?
    * ispbridge of JCLiu
    (cctu) code排版
    (cctu) ICP tool 起始畫面 auto select
    (cctu) upload nubridge by jcs2
                     
        
    ** >> code review: 6603

    (yung/zale/ccli) m480/sfr nutool/isp
    (cyyu) github pinconfig
    pri (ccli) UAC/NM18xx 包含多種 die, sw arch 如何改?
    pri (ccli) sync cctu's icptool.lua code
    
    (wait) win7 64bits to win10 64bits to reproduce bug on white NB

    .inf problem
    (ycc) NVIC, offline cert upload
    (ccli) special part flow 
    (yung) etm output verification automatic
        
    weekly report track item backup
      [Nu-Link] firmware upgrade flow refine (TBD)
    	若廣灑也沒有什麼結果, 在v1.32還能夠加一些補強的點
    	Verify all APROM while ICE fw update (todo)
    	Verify LDROM while ICE fw update (done)

    	[Nu-Link][Mbed] Mbed CMSIS DAP debug interface (TBD)
    	CMSIS DAP interface implement
    	pyDAPLink benchmark.py for CMSIS-DAP compliance
    	Test DAPLink script

    
>> CCMa     
    pyOCD as isp/icp tool on linux
    FPGA occupy location
    C:\Users\CCMA\Documents\Outlook Files
    >> 幼兒園, 學區, 防盜監控, dna preserve, 清冷氣, NAS, 防網路霸凌 reverse search engine, 效能促進公司, 買體重機
    >> 二進制比對工具, not only implement tool but find fit tool (like project management) 
    >> 電腦工作環境整理, clean disk, 如何切出自己工作, 電腦報廢
   
    ##git 
        [p4merge](https://git-scm.com/book/zh-tw/v1/Git-%E5%AE%A2%E8%A3%BD%E5%8C%96-Git-%E9%85%8D%E7%BD%AE#格式化與空格)
        ssh - push remote with keyin username and password
            ssh-keygen
                have to key in password for id_rsa key
                clip < ~/.ssh/id_rsa.pub
                paste public key on github                
            eval `ssh-agent -s`
            ssh-add ~/.ssh/id_rsa
            ssh -T git@github.com            
            git remote add origin git@github.com:your_account/your_repository.git
            git clone git@github.com:Username/repository.git
        practice 圖解git, remote push/pull
        gerrit ppt
        note
            git hash-object 'file name' 
                list blob hash
            git cat-file -p master
                list tree ids
            git cat-file -p 'tree id'
                list tree file
                
    >>efficient        
        note7 chrome 手機模式瀏覽
        markdown insert http link but can't display on website default, need to delete all the indent 
        sublime 讀檔二進位轉換 edit config0 is possible?
        sublime how to collapse & unfold yaml format
        sublime search but can jump to result directly, need to mouse click
        command windows paste & copy, file browswer that can keep previous setting
        01937 can't new txt file by right key mouse 
        01937 use AndroidAP, PC also use, PCANY WHERE , delete wormhole
        如何快速reget windows 工作快取
        linux server as NAS and github server
        TruethCrypt like tool for photo, 檔案徹底格式化, image temp icon delete
        use sublime to read code
        simple chinese system of my PC
        update this note to GitHub
        word file format of bullitin one key fixing
        weekly reports word/pdf files keyword search
        which search engine can escape special character like '-' of "-Wa"
        how to index to saving files, e.g. index to icptool by yung in pt30 extension
        crontab backup working notes
        notepad++ text cloud index(no classify) 結合平日生活&learning
        notepad++ define your own language??
        notepad++ priority highlight with color and can be filtered out for clear view
        notepad++ add hyperlink to note, sync with ubuntu PC, google keep manage/GitHub, can .HTA FILE do this??
        notepad++ indent, when press enter on a title
        windows wormhole with ubuntu ??
        x555l 
            ubuntu display blink 
            win10 64bit installation for multi os
            ssh to x555l remote    

    ##screen
        history share howto ?
        shutdown screen preserve 

        % screen -ls
        % screen -r
        C-a d
        C-a ? 線上求助畫面
        C-a c 或 C-a C-c 開啟新的視窗，並同時切換到這個新的視窗

        C-a n 或 C-a C-n 或 C-a (space) 切換到下一個視窗（0->1 1->2 ...）

        C-a p 或 C-a C-p 切換到上一個視窗（1->0 2->1 ...）

        C-a C-a 切換到上一個顯示過的視窗（不是照順序切換）

        C-a 0 切換到第 0 個視窗

        C-a (1..9) 切換到第 (1..9) 個視窗

        C-a w 或 C-a C-w 會列出目前所開啟的視窗

        C-a K 關閉所有的視窗並退出 screen

        C-a ' 或 C-a " 會出現 "Switch to window:" 字樣，輸入號碼後就可切到該視窗

        單一視窗使用中的指令

        C-a C 清除目前的視窗內容

        C-a d 或 C-a C-d 脫離（detach）目前的 screen 

        C-a D D 強力脫離，除了放到背景執行外，並自動 logout
        C-a "   see window list and select

        give screen session a name
        screen -S foo
        then you can recover by 
        screen -r foo

        C-a A - rename a window
        C-a ' name - jump to name'window

        C-a [ or C-a Esc will enter copy mode
        Esc or Enter twice will return from that mode
        C-a ] can paste the copied data 

        split
            C-a S or C-a V
            C-a tab
            C-a Q (keep only this) or C-a X (leave this)

    ##unix        
        set & share 環境變數 for multi terminal 
        system programming   
        制作路徑變數方便切路徑, cd $libnano
        solved
            sudo apt-get install xclip
            cat txt | xclip
            xclip -o 
            cat txt | xclip -selection clipboard
            C-S-v
            env | grep ARMGCC | xclip -selection clipboard

            Use Ctrl + Left and Ctrl + Right to move between the various parts of line

            clip < c:/Users/CCMA/.ssh/id_rsa.pub
            cd – 	cd 減號；切換目錄到前一個目錄
            ls -F 	附加檔案類型，目錄附加/，執行檔附加`*
            locate 檔案 	搜尋符合的檔案或目錄；必須先用updatedb建立檔名索引。
            locate -b ‘\name’列出名為name的檔案，沒加反斜線的話
            也會列出部份符合的檔案
            which 執行檔名 	列出執行檔名所在路徑
            Ctrl+L 	清除螢幕，同clear命令
            Esc + . 	顯示上一命令的引數、修改後執行
            Ctrl+A 	游標移回開頭位置
            Ctrl+E 	游標移回最後位置
            Ctrl+U 	剪下游標前方所有文字並複製到暫存剪貼簿
            Ctrl+K 	剪下游標後方所有文字並複製到暫存剪貼簿
            Ctrl+Y 	由暫存剪貼簿貼上Ctrl+U與Ctrl+K剪下的文字
            Ctrl+W 	刪除游標前方的單字(Word)
            Ctrl+Shift+C 	複製標示區的文字到剪貼簿
            Ctrl+Shift+V 	貼上剪貼簿文字到Terminal裡
            標示、滑鼠中鈕 	先用左鈕拖拉選取需要的文字後移動游標到新位置按中鈕
            （兩鈕滑鼠則是同時按左右鈕），標示文字會被複製到新位置
            date 	顯示系統日期與時間
            cal 	顯示本月月曆
            uptime 	顯示開機時數
            w 	顯示上線用戶清單
            whoami 	顯示目前用戶名
            uname -a 	顯示系統核心資訊
            cat /proc/cpuinfo 	顯示CPU資訊
            cat /proc/meminfo 	顯示記憶體資訊
            df -h 	Disk Free，顯示磁碟空間資訊
            du 	Directory Usage，顯示目錄的磁碟用量
            free 	顯示記憶體與Swap區的用量

            history | grep sudo\ a*

            print match string and follow-up lines - 印出 g3 相關前後5行 grep -A5 -B5
            grep exact match - grep -w 'word'
            ARMGCCPATH=`pwd`
            echo $ARMGCCPATH 
            /usr/lib/gcc/arm-none-eabi/6.2.1

            find result filter
            find / -name "arm_cmse.h" 2>/dev/null
            find / -name "arm_cmse.h" 2>&1 | grep -v "Permission denied"

            ls -tl --time-style=full-iso
            
            『var="lang is $LANG"』則『echo $var』可得『lang is zh_TW.UTF-8』
            『var='lang is $LANG'』則『echo $var』可得『lang is $LANG』
            變數與變數內容以一個等號『=』來連結，如下所示： 
            『myname=VBird』
            等號兩邊不能直接接空白字元，如下所示為錯誤： 
            『myname = VBird』或『myname=VBird Tsai』
            可用跳脫字元『 \ 』將特殊符號(如 [Enter], $, \, 空白字元, '等)變成一般字元，如：
            『myname=VBird\ Tsai』

            [dmtsai@study ~]$ work="/cluster/server/work/taiwan_2015/003/"
            [dmtsai@study ~]$ cd $work

            [dmtsai@study ~]$ myname="$name its me"
            [dmtsai@study ~]$ echo $myname
            VBird its me
            [dmtsai@study ~]$ myname='$name its me'
            [dmtsai@study ~]$ echo $myname
            $name its me

            [dmtsai@study ~]$ cd /lib/modules/`uname -r`/kernel
       
            indent -st -i2 test.c <- -st means write file, -i2 means indent format
    >>vim  
        how to auto set tags in vim, ctags -R can't recursive add sub directory also do 'ctags' in subdir, and set tags+=subdir
        ctags can't resolve local variable
        refresh vim content
        alias alert
        delete bracket line automatic - 自己用 C 搞定
            For selective deletion of certain lines sed is the best tool. To print all of file EXCEPT section between WORD1 and WORD2 (2 regular expressions), use
            $ sed '/WORD1/,/WORD2/d' input.txt > output.txt

            #!/bin/bash
            # ALL HTML FILES
            FILES="*.html"
            # for loop read each file
            for f in $FILES
            do
            INF="$f"
            OUTF="$f.out.tmp"
            # replace javascript
            sed '/<script type="text\/javascript"/,/<\/script>/d' $INF > $OUTF
            /bin/cp $OUTF $INF
            /bin/rm -f $OUTF
            done
        ctags
            set tags=tags;/
            In case you get here and, like me, are puzzled by tags;/, the ;/ suffix directs vim to do an upward search from the directory 
            containing tags up to the stop directory, in this case /. If you want to use your home directory as the stop-directory, 
            use set tags+=tags;~ or set tags+=tags;$HOME. Or you could use the top directory of your project tree as the stop directory. 
            (See :help file-searching to understand the semi-colon.) Note also that searching for the tags file will be affected by autochdir. 
            I use in my .vimrc set tags=./tags,./TAGS,tags;~,TAGS;~
                                   
            set tags=./tags,tags;$HOME
            set this in ~/.vimrc, tell vim to look for tags file, from current dir up to $HOME
            
        solved 
            to delete all lines containing "profile"
            :g/profile/d
            :g!/profile/d  <- to delete all lines NOT containing "profile"
            
            :set ic(ignorecase 的??) 忽略大小?
            :set noic(noignorecase 的??) 不忽略大小?
            /\CWord ?分大小?的查找
            /\cword 不?分大小?的查找

            vsp 
            
            vim history
            q:
            :set li<up>
            :set lines=75
        
            exact match word - /\<your_exact_word\>
            用VI寫程式時，常常要到shell中執行Make，這樣exit--edit反覆，很麻煩。

            VI中職行shell command有兩種方法：
            一是只執行一個command:
             : ! 命令
            另一個是跳到shell，直到用exit回來:
             : shell
            好像還有一個方便Make的功能.....
            在要mark的位置，command : m{a-zA-Z}
            (直接輸入command，不用 : 符號和進入edit (insert) mode).
            所以可以mark 26+26 個。

            要到某一個mark : 用
             `{a-zA-Z}
            連續兩個 ` 會到剛剛mark的位置。

            .要列出所有marks:
             :marks
             
             delete marks
             delm a-z0-9

             一個超好用的開檔編輯command
             gf
            會開啟游標所在word為檔名的檔案。
            在 開include檔時很有用。

            列出目前所有開啟的file:
            files

            跳到下一個edit的file
             Ctrl - ^
            多檔編輯時，每一個file是一個buffer，buffer的command都是以 b 開頭的：
            :bn  編輯下一個開啟的buffer(file)
            :bp  編輯上一個
            :bd  刪除這一個
            :b{數字} 編輯第N個              

            刪除從游標開始後的word - dw
            刪除從游標開始後至結尾 - d$

    >>mbed
        mass mode
        If GPA.1 = 0
            if GPB.14 = 0       
                    Mass Storage ISP. 
            else
                    Boot from AP.
                    MBED (MSC + VCOM)
        else
            ICP Tool, KEIL比對ICE Firmware的版本.跑既有Firmware Update的流程.
            
    >>m2351         
        * interrupt vector table 
        gdb disassembly, set in assembler code?
        keil axf.c will get LOAD region of elf file to specify where KEIL load to?	
        
            
    >>newlib
        issue
            > flash write_image erase tz_gcc.elf 0x0
            auto erase enabled
            Device ID: 0x00945330
            Device Name: M4d53VD3AE
            bank base = 0x00000000, size = 0x00012000
            Nuvoton NuMicro: Sector Erase ... (0 to 8)
            Nuvoton NuMicro: Flash Write ...
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            NuMicro.cpu: target state: halted
            target halted due to breakpoint, current mode: Thread 
            xPSR: 0x61000000 pc: 0x2000002e msp: 0x20000448
            Device ID: 0x00945330
            Device Name: M453VD3AE
            bank base = 0x0001f000, size = 0x00000000
            Device ID: 0x00945330
            Device Name: M453VD3AE
            bank base = 0x00100000, size = 0x00001000
            Device ID: 0x00945330
            Device Name: M453VD3AE
            bank base = 0x00300000, size = 0x00000008
            no flash bank found for address 3f800
            wrote 18432 bytes from file tz_gcc.elf in 5.632781s (3.196 KiB/s)
 
        trustzoneGCCUv .S file can't be build 
        有什麼工具可以 disassemble 一小段機械碼
        armv8m page 216, B{<c>}{<q>} <label>, gnu assembler of WK7, mvn  r3, #0xFF, asm("ldr r3, =JMPADDR");
        what's this mean? M32(0x3001FFF0) = 0xe7fee7ff;
            branch to 0xE7FF and stay in 0xE7FE
            0x3001FFF0 E7FF     B 0x3001FFF2
            0x3001FFF2 E7FE     B 0x3001FFF2
        getchar 有時terminal send 一個a, 二次getchar () 呼叫都抓到a
        $ ./configure --target=arm-none-eabi --enable-newlib-nano-malloc --enable-newlib-reent-small --enable-newlib-nano-formatted-io --disable-newlib-multithread --disable-newlib-supplied-syscalls
        newlib build problem modification
            Error: lo register required
            C:\git\newlib-2.5.0\newlib\libc\sys\arm\crt0.S Error: lo register required
            C:\git\newlib-2.5.0\newlib\libc\sys\arm\trap.S  @SUB     ip, sp, ip      @ extra stack required for function
        * gitm2351 bsp tz enable DEBUG_ENABLE_SEMIHOST __attribute__((weak)) weak symbol hardfault process fail
        * core_armv8mbl.h et al include file can come from gcc built-in?        
        * It seems current GCC can’t generate NSC segment on 0x2000fc00, so change to put in flash (say 0x3f800)
        * keil local variable can't be watched, must move to global? char s[] (be optimized by compiler? volatile?)
        * build newlib code on windows platform, project sample retarget, and debug
        * GCC share library/ dynamic linking --static .so,  practice debug with --static
        why KEIL MicroLib no need HEAP for printf??
        #pragma message
        trace newlib code after preprocessor to strip DEFUN
        gdb arrary ub[20]. p ub 為何和 p &ub 不同? printf %x &ub 卻和 ub 相同?
        preprocessor 可以看到 define 被取代成什麼, 但是可以看出這 define 打哪來?
        can retarget _write, but not weak symbol ?
        KEIL USB sample 的 struct 學習
        #define errno (*__errno())
        arm assembly and addressing mode
        如果你是想寫一些 UNIX 或 LINUX 系統程式，我那時代用的是 Advanced Programing in UNIX Environment，簡稱 APUE。如果想寫網路程式，我們用的是unix network programing。這兩本書都有個特色；就是循序漸進的介紹各個函數然後搭配小程式，只要照著打就可編譯成功。我強烈建議學的人自己打範例程式，不過有時候我也偷懶，去 APUE 的網站下載原始碼以縮短時間。這兩本是程式設計的書，至於函式庫的書我是直接跟 GNU 買的，就是 GNU C Library Application Fundamentals, GNU C Library System & Network Application.        
        how malloc work on GCC?
            羅習五
        _reent - libc/include/sys/reent.h strct _reent{ union struct {}_reent}
        __STDC__ of gcc        
        一堆 ifdef endif 要怎麼看
        note
            check version
            arm-none-eabi-gcc -v
            make -v
            
            GCC inline assembler
            C:\weekly report\note\htm\ARM GCC Inline Assembler Cookbook.html

            --defsym end=__HeapBase -DDEBUG_PORT=UART0_NS
            
            Replacing symbolic names of C functions
            extern long Calc(void) asm ("CALCULATE");
            
            arm v8m project copy to ubuntu and build

            CC=arm-none-eabi-gcc AR=arm-none-eabi-ar ./configure cross_compiling=yes --host=arm-unknown-none

            newlib/Makefile:   
            -O0 -g3 -mcpu=cortex-m0 -D__SINGLE_THREAD__

            unix2dos

            core_cmInstr.h

            usr/share/arm-gcc-embedded/samples <- try this first

            arm-none-eabi-gcc -g3 -O0 main.c retarget.c ../../startup/startup_ARMCM0.S -mthumb -mcpu=cortex-m0 -L../../ldscripts -T gcc.ld -L. -lc -o retarget-CM0.axf

            diff -cw testdiff1 testdiff2

            echo 'main(){}' | gcc -E -v -
            #include <...> search starts here:
             /usr/lib/gcc/x86_64-linux-gnu/5/include
             /usr/local/include
             /usr/lib/gcc/x86_64-linux-gnu/5/include-fixed
             /usr/include/x86_64-linux-gnu
             /usr/include

            newlib libc/include/sys/reent.h
            if defined(__DYNAMIC_REENT__) && !defined(__SINGLE_THREAD__)   

            libc/sys/arm/syscalls.c
            int     _read           _PARAMS ((int, char *, int)) __attribute__((weak));
            int     _swiread        _PARAMS ((int, char *, int)) __attribute__((weak));
        cLang study
            NVCZ flag forget 
            Tex
            strtok(string, tok)連續2次, 再 strtok(NULL, tok) 就不能正常 output 後面的 token
            tok "--" 和 "-" 好像都一樣
            ctags will fail on _DEFUN? jump to strange position and not it's definition.
            * ctag, cscope  - _DEFUN  
            gprofile
            fscanf - can we decide delimiter and what's the default?
            crc16
        gcc
            gcc預設會去尋找headers的目錄大致有：
                /usr/include
                /usr/local/include
                /usr/src/linux-headers-`uname -r`/include
                /usr/lib/gcc/i486-linux-gnu/UR_GCC_VERSION/include
                可以利用多個-I來指定多個headers的路徑
            gcc預設會去找lib 函式的目錄大致有：
                /usr/lib
                /usr/local/lib    
                /usr/src/linux-headers-`uname -r`/lib
                /lib/modules/`uname -r`/kernel/lib
                /lib
                可以利用多個-L來指定多個lib路徑
            static library
                gcc operator.c -c
                ar crsv liboperator.a operator.o
                或者
                gcc -static operator.c -loperator
                要與靜態函式作鏈結也很容易
                gcc main.c /usr/local/foo/lib/liboperator.a -o main
                或者
                gcc main.c -L /usr/local/foo/lib -loperator -o main
            link "gcclib.txt"
            
            If you want to see the C code together with the assembly it was converted to, use a command line like this:
            gcc -c -g -Wa,-a,-ad [other GCC options] foo.c > foo.lst       
            -Wa,-alhms="*.lst" <- that's excerpted from keil arm-none-eabi option
            -alhms="*.lst" <- if arm-none-eabi-as, use this directly
            
            use -E -dM options instead of -c. Example (outputs them to stdout):
            gcc -dM -E - < /dev/null
            touch foo.h; cpp -dM foo.h
            
        solved
            inline assembly的 通式是
            >__asm__(asm statements : outputs : inputs : clobber);
            show hll with assembly, build with -g3, objdump -S
            > iprintf can't find alias printf
            > memchr(origin, '/0', strlen(origin)) <- if there is no /0 char in origin, return null, if there is one, you see nothing from printf, because the string starts from '/0'
            strtol - for (acc = 0, any = 0;; c = *s++) 
            #define	_DEFUN(name, arglist, args)	name arglist args;
            carry/overflow bit C V N Z of arm instruction
                - overflow has meaning for sign number -- add - if bit6, bit7 didn't carry toghter, OV = 1. sign 8bit represent values from -128 to 127
                - carry has meaning for unsign number -- add if carry msb carry=1, sub if no borrow carry=1     
            
    * ropi - do experiment        
        generate pc relative branch code. 
        TODO - dynamic linking vs PIC code
        TODO - gen a immediate pc branch, and enable ropi, rebuild and see what happens
        TODO - how about rwpi?
    * write c++ oop sample to achieve polymophism, and strategy pattern
        scratch
        class A1:A0{
            
        }
    KIEL microlib
        where does default printf go? of KEIL 
        malloc
    * run keil flash algo parsing
    * struct - 關於 new 與不new 的 address 差異
    * struct 宣告與定義, and typedef
    * vim detect tag, and delete lines with tags
    
    context switch - thread has schedule and context switch, how to interact with process?
    tail recursion how to parallel? - i know it can save stack usage
    why c lang can't be interpret?
    tty , modem
    mbed uVisor
    beautiful code
    crawler - video can be GET from server?  
    c語法技巧
    naming rule (class, struct, enum, define)
    Qemu
    doxygen
    design pattern - stratergy, c lang ** struct archtecture
    unit test
    core dump
    IOT maker
    thread stack 獨立?
    function programming
    rootfs
    regular expression
    TYPE array[n] <- array is a pointer (where is it?) array point to a buffer length TYPE*n (where is it location? stack?)

    callback 使用時機 (記得有create thread, and init.d??)
    Linux就該這麼學
    computer science from buttom up
    Linux System Programming
    代??? Code Reading
    
    keil flm erase after program
   
    >> 3600
    >> VCOM driver of NuLink, remove VCOM, send \\nuvoton.com\public\MS20\YT\vcom_driver_signed to ms10, ms20
    >> ICPTool chip type auto detection (suggest by CCTu), may implement in Nu-Link2.0
    >> icp tool archtecture analysis
    >> cannot set Watchpoints on-the-fly while the program is running like you can with hardware breakpoints??
    >> ICP tools .icp project 導入 不給改
    >> ropi warning? dh bits 256 ram usage, aes buffer need
    >> 又把 private key 傳出來, pAxf->PowMod_Finish(auPwdB2);
    >> icptool set swd clock?
    >> pinconfig autotest (20%), check jquery of pinconfig
    >> ytlu auto test, not reset 測的到嗎? 語系問題, flash lock 之後的chip erase + download, ICE pin switch to GPIO, config modify then download test.
    >> (self) doxygen, git share file how to, pinconfig 的自動測試方法? study EMAC, vs2010 feature pack2, include manager
    >> (minor) ccli nuCMD talk with AP, how to? can only return one byte status
    >> (minor) build code unicode for vs2008 (hid.cpp all 亂碼)
    >> (minor) KEIL/IAR user manual (html devices merge into user manual)
    >> (minor) offline fail 的閃燈無法 identify error
    >> (minor) 增加測項  簡体和日文檔名, nulink vcom

##YCC
    >> ICP Lib release
    >> NUC505 sector erase, backup or sector align
    >> SPIN button DFBA 問題: Mini51DE/58DE, NUC029AE, NUC200. ICP tool更改Bass address後Config1不會跟著變動

##cctu
    >> isp link
    >> [FAE Case - NuMicro Family 0006345]: 需要用SPI介面的ISP sample code
    >> [FAE Case - NuMicro Family 0006281]: CAN ISP sample code
    >> NUC122 I2C ISP MF10 JLIU 
    >> Nu-Bridge WinUsbLib API說明文件
    >> migrate vs2008 to vs2010
    
##ccli 
    NuCommand tool run on linux??    
    >> ALOCK M451 連動 security lock    
    >> ICPTool customize issue
    >> icptool.lua code
    >> multi projects can't coexist
    icptool install new beta version, force uninstall previous version
    (ccli) nuCMD chip reset 電掉不下去, 但之前Nano100接著 target好像反而是會掉下去而連不上去??
    >> advice lunaII
    >> CCLi: PDID 表格整理, 連 special part 等等..
    >> target dll has been cancelled , debugger aborted
    >> kprom/sprom suggestion
        sprom 燒錄  需要提示使用者是否真的要燒寫
        KPROM  就不存密碼和錯誤次數顯示的UI部分  需要修改
    >> tc8226, tc8222 whole chip erase 不包含 config
    >> Data Flash Emulates EEPROM, add alert
    >> LDROM 燒錄為何 verify 不全驗, 要用 checksum??
    >> 客戶反饋表: 我們在下一nulink版本試著改成不用重新ICE上電, 按鈕就可以繼續燒下一顆 (from WB), icp specific area 下一版ICP脫機燒寫模式default需要將此選項勾選起來。
    >> nulink 安裝包加個b, exe to zip
    >> icptool connect and read flash add an option for it
    >> (autotest) add ISPTool? sync yt's auto test source to svn, config0 應該寫某些 bit 要跳出來看看能否燒錄, 
    >> (autotest) nano112 config0 跑不過, 手測ok. ychsu flash select and config0 要設一樣才能進 debug mode 這問題 auto test can't find??
    >> icptool 印出 寫入大小超過了數據Flash的限制 不斷重連 
    >> Nano112 SPROM in KEIL need to set .ini verify=0??
    >> (minor) nuCAD can't launch OrCAD at first time (if not reboot)

Yung
    >> cdc at win10 don't need to install driver, nulink driver can pass?
    >> ETM register control, verification list, trigger packet, golden pattern.
    >> KEIL read config0/1, use connect under reset
    >> pinview : keil bottom can't show, offd display, list registers and clock information
    >> (yung) if didn't update config0 bit0, need chip erase?? chip erase 完馬上把 config0 值寫進去再 chip reset
    >> 是不是要加個environment variable來標示Nuvoton Tool位置 , ws iar problem (regedit不是有?)
    >> iar connect no reset by david
    >> iar 是如何支援 NUC501? flash algo?
    >> ICP Tool, NUC100DN, APROM單獨燒128K,	Option: Erase + Program+ Verify + Reset chip	v6373r	v6254r	Time	35s	27s	 (v6373 有灌bulk 35s, 移除反變27s)
    >> config0 security lock 不 erase chip, security unlock 才 erase
    >> (check) ICPTool download finish read flash (cy0, should be remove) 時切走 ice pin 會一直重連 (reset and run enable), batch mode 也會, 若是 online download 用 offline download 的方式, connect (normal then under) instead of check_usb 似可解
    >> KEIL new project 時選 device 又要選 chip type 有點怪, 若純增加 PID 可用 soft pack update 但 read 出 DID 查無登錄就說是 unknown device 
    >> online + batch mode 檢測機制是檢查 ID_CODE, 為何不要學 offline 重連到連上為止, 即一定要target 被 unplug 再重插才會 upgrade 下一塊 
    >> Improve general 選項 (support multi FLM)
    >> (minor) pin view (show CPU clock)


Zale 
    >> Clock config default 選 NUC121, 加 cookie keep previous setting
    >> __HXT 120000000 寫死
    >> CYYu study more sensor  ---                                               
    >> zale's code backup
    clock configure 設計問題
        1. pin 選了 ip, 傳給 clock 繼續用 (stored selected ip) 反之亦然
        2. stored ip list 只記錄選的 ip, 出 pin 另外存
        3. selection guide 並不一定都能出 pin 完整, 要如何克服 pass to pinconfig?
        >> switch off the tips, tips move with cursor
    >> [FAE Case - NuMicro Family 0005848]: M451 VCOM 的?字?名上位机?? 
    >> clyu low power of nano100
    >> pinconfig power down setting version
    >> NuWizard 
            CPU clock 加入選型表?
            pin 選型表選完, 己經知道 user 對週邊的需求, 是否能在 pinConfigure 幫 user 帶好設定?
            clock 透過每個 module 是否有需要在 standby work, 選擇 LIRC or HIRC
                clock config 應該要根據 pinconfig 使用到多少 module 直接帶入 used modules information (如選型表到pinConfig)
                  tool 之間的連動, 要先 enable external clock pin (of pinConfig), external clock 才可以起作用
              在 pin config -> clock config 間跳一窗問 user 哪些 module 要 power down work? (auto gen clock DIV plan) 讓user 自己選擇哪些module 是要在低速運行
            ip 設定想要的 clock speed, 分析是否可達需求. 剩下的 module init					
    >> clock configure (PLL 範圍, PLL警告視窗跳出來的規則)
         (SPEC) 自動提出最佳解 (bese performance -> UART highest baudrate + SPI highest clock rate, best power saving) 如 UCH 使用 PLL2 for performance, PLL1 for power
         (SPEC) USB PHY in PLL2 not work by YCHuang3 -  it can not be ignored
         (SPEC) 未滿足之 module 要先反灰, 並 prompt 未滿足條件	  
         (SPEC) 先把必要條件的 path 填上, 如 UCH 使用 PLL1 48MHz, 並讓 PLL1 限制於 48MHz, 若 CPU 想改成 84MHz, 顯示 limitation
         (limit) PLL 有 range 限制, mini51 只能開 HXT/LXT 其一, USB一定要HXT, LCD一定要LXT	 
         //(improve) config0 有一些 CPU clock, X32, XT 的 reset default value - 這個有需要做在 clock configure? 不設 config0 有關係嗎?
         //(improve) code gen 之 AHBCLK, 因為是enable module, 應該要在最後一個設定的 register, 等其它 clock register 都 ready 好之後再設定
         //(improve) clock module 沒有 CPU? 
         //放在 nusmart - (improve) gen uVision project uvproj file 
         (check) c code LOCKREG 回到原狀態, 原來lock就lock, 原來unlock就unlock, 而非強制lock
    >> (minor) RTS CTS control flow, win driver 開發用 hardware


TBD
>> if((flashInfo.uConfig0 & NUC1XX_FLASH_CONFIG_LOCK) != 0) in HasFlashForOfflineDownload() always false
>> The Nu-Link device may be detached temporarily, Continue to wait for the device
>> (minor) NuConsole 和 NuBridge 搞不好有相同之處 
>> (minor) "using obsolete header file usbioctl.h" #pragma warning(disable:2220) #include <usbioctl.h> #pragma warning(default:2220)
>> (minor) ICPTool offline 超過size燒寫失敗 error msg 不明確 ICE: Cmd error: ERROR_FLASH_WRITE 
>> (minor) because flash algo source code is open) download 完清掉 sram 中的算法程式, 怕亂跑code
>> (patent) implement the pattern: MFP pin debug
>> (patent) GPIO/UART/I2C timing protocol generator
>> CPU clock 加入選型表?



使用說明書增加項目
>> [ICPTool] offline flash verify fail : exception all LED on, quick start, green group word remove
>> [KEIL] EnableLog = 1, Memaccr, bulk USB driver install, conditional breakpoint, ICP merge exe file
>> [nulink] error message
>> [nulink dongle] detect target power
>> file name rename to UM_
1.1.1	Device Family Pack
After KEIL MDKv5.0, Nuvoton also provide “Device Family Pack”, you can install that if you need it. (About the detail of “device family pack” please check KEIL website http://www.keil.com/pack/doc/CMSIS/Pack/html/index.html)


ICPTool customize
>> NuvotonICP.lua 刪 Nuvoton (可直改)
>> ICE_ISP.bin ICE_M0.bin, path and name 去 Nuvoton (可直改)
>> rc file customize (SVN local, common part that can use #define)
>> bmp (SVN local)
>> iss file (SVN local)
>> part number display (SVN local)
>> mark netcheck, chip type select menu, language (SVN local)
>> add auto-build (add)
>> CTMR version control (add)


eng
    squelch, git push.default 


wise    
    11. 禪修，不必到廟裡，能夠心平氣和地oooo，就是最好的修行。
    we believe that “empty vessels make the most sound”; this, however, could not be further from the truth
    規則就在那裡, 只是輸的人不干心罷了
    目標明確, 就不會打忙

<transfer>
    (cctu) how to exchange data between c++ and js
    (cctu) nusenadj
    (ycc) nugang, mbed, 8051
    
</transfer>

>>c++ notes
    ctraps note
        ‘‘If the input stream has been parsed into tokens up to a given character, the next token is taken to include the longest string of characters which could possibly constitute a
token.’’
        y = x/*p
        except: a + /* strange */ = 1 means the same as a += 1. These operators are the only cases in which things that look like single tokens are really multiple tokens
        p - > a is illegal

        printf ("Hello world\n");
        char hello[] = {’H’, ’e’, ’l’, ’l’, ’o’, ’ ’,
        ’w’, ’o’, ’r’, ’l’, ’d’, ’\n’, 0};
        printf (hello);

        writing ’yes’ instead of "yes" may well go undetected. The latter means ‘‘the address of the first of four consecutive memory locations containing y,
        e, s, and a null character, respectively.’’ The former means ‘‘an integer that is composed of the values of
        the characters y, e, and s in some implementation-defined manner.’’

        (*(void(*)())0)();

        c precedence
        1. The operators that bind the most tightly are the ones that aren’t really operators: subscripting, function calls, and structure selection. These all associate to the left
        2. Unary operators are right-associative, so *p++ is interpreted as *(p++) 
        3. Next come the true binary operators, . The arithmetic operators have the highest precedence, then the
            shift operators, the relational operators, the logical operators, conditional operator, assignment operators. The two most important things to keep in mind are:
            One small surprise is that the six relational operators do not all have the same precedence: == and != bind less tightly than the other relational operators.
            a < b == c < d 
            z = a < b && b < c ? d : e
        a = b = c        the same as        b = c; a = b;


    //keil
    -c -mthumb -gdwarf-2 -MD -w -O -mapcs-frame -mthumb-interwork -I ../../../../Library/CMSIS/Include -I ../../../../Library/Device/Nuvoton/TC8234/Include 
    -I ../../../../Library/StdDriver/inc -I ../Secure -IC:/temp/v8m/TC8234_BSP/SampleCode/TrustZoneGCC/Template/Secure/RTE -IC:/keil/520s/ARM/PACK/ARM/CMSIS/5.0.0-Beta4/Device/ARM/ARMv8MBL/Include 
    -IC:/keil/520s/ARM/CMSIS/Include -I"C:/Program Files/GNU Tools ARM Embedded/5.4 2016q2/arm-none-eabi/include" -I"C:/Program Files/GNU Tools ARM Embedded/5.4 2016q2/lib/gcc/arm-none-eabi/5.4.1/include" 
    -I"C:/Program Files/GNU Tools ARM Embedded/5.4 2016q2/arm-none-eabi/include/c++/5.4.1" -I"C:/Program Files/GNU Tools ARM Embedded/5.4 2016q2/arm-none-eabi/include/c++/5.4.1/arm-none-eabi" 
    -D__UVISION_VERSION="520" -D__GCC -D__GCC_VERSION="541" -DARMv8MBL -D__ARM_FEATURE_CMSE="3" -o *.o 


    //eclipse
    'Building file: ../src/stm32f4xx_hal_msp.c'
    'Invoking: Cross ARM C Compiler'
    arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 
    -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F407xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" 
    -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"src/stm32f4xx_hal_msp.d" -MT"src/stm32f4xx_hal_msp.d" -c -o "src/stm32f4xx_hal_msp.o" "../src/stm32f4xx_hal_msp.c"
    'Finished building: ../src/stm32f4xx_hal_msp.c'
    ' '
    'Building target: stm32ya.elf'
    'Invoking: Cross ARM C++ Linker'
    arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"stm32ya.map" --specs=nano.specs -o "stm32ya.elf"  ./system/src/stm32f4-hal/stm32f4xx_hal.o ./system/src/stm32f4-hal/stm32f4xx_hal_cortex.o ./system/src/stm32f4-hal/stm32f4xx_hal_flash.o ./system/src/stm32f4-hal/stm32f4xx_hal_gpio.o ./system/src/stm32f4-hal/stm32f4xx_hal_iwdg.o ./system/src/stm32f4-hal/stm32f4xx_hal_pwr.o ./system/src/stm32f4-hal/stm32f4xx_hal_rcc.o  ./system/src/newlib/_cxx.o ./system/src/newlib/_exit.o ./system/src/newlib/_sbrk.o ./system/src/newlib/_startup.o ./system/src/newlib/_syscalls.o ./system/src/newlib/assert.o  ./system/src/diag/Trace.o ./system/src/diag/trace_impl.o  ./system/src/cortexm/_initialize_hardware.o ./system/src/cortexm/_reset_hardware.o ./system/src/cortexm/exception_handlers.o  ./system/src/cmsis/system_stm32f4xx.o ./system/src/cmsis/vectors_stm32f407xx.o  ./src/BlinkLed.o ./src/Timer.o ./src/_initialize_hardware.o ./src/_write.o ./src/main.o ./src/stm32f4xx_hal_msp.o   


    <nulink>
        app_config 和 dialog 都 include lua.h 及 appconfig.h.  
        因為 CCTu 用不到lua.h
        把 lua.h 放到 appconfig.h include
        他用一個 fake appconfig.h header 可以拿去用
    </nulink>

    Questions
        openocd - src/flash/nor/core.c
        js 的程式入口在哪?
        closure usage
        heapsort (select) shellsort (insert) quick sort
        dbg monitor of cortex A
        regtarget.c of secure project 
            1. asm("MOVS    r0, #4                        \n". 
            2. __asm int32_t HardFault_Handler(void)
            3. DEBUG_PORT-> 用 define 的寫法
        symbol table    
        hanoi tower and queue data structure
        LISTING 14.10 is worth to study
        c++ dependency tool (except vs2012 ultimate)
        void() const -- try to tamper with it
        baseptr = (* baseptr) derive class.  => delete derived obj -> can we see derived destructor?
        DLL and library of visual studio
        code optimize can reduce size in unused code in library?? GCC/binutils can do this if you compile with -ffunction-sections -fdata-sections and link with --gc-sections.  
        c++11 rvalue reference
        (network) mac address is burn on nuvoton chip?
        static method is what?
            #ifdef USE_SW_SPIMODE
            static 
            #endif
            void ConnectToDevice();
            
        1. copy constructor and assignment (need deep copy in general case?)
        const 是否不能傳進 non-const as parameter in func?
                     
                     

        vfprintf(stderr, fmt, va); stderr of visual studio means?
        C++’s scope-resolution operator　::warming

        
        read effective c++ 
        refactory
        c pitfull

        
    >>  function pointer parameter 
            void  A (void (*)()) - it's function pointer type
        
    >>  linux 
        find . -name "*.c" | xargs -p rm -f

        rm -f ./G T Wang.c
        因為檔名包含空白，所以這會會造成 rm 指令無法正確刪除該檔案
        find . -name "*.c" -print0 | xargs -0 rm -rf

        find . -name '*.c' | xargs grep 'stdlib.h'

        ls long-long-filename1.txt long-long-filename2.txt
        cat !$

        ls long-long-filename1.txt long-long-filename2.txt long-long-filename3.txt
        cat !:2

        ls long-long-filename1.txt long-long-filename2.txt long-long-filename3.txt
        pwd
        cat !ls:2

        ls long-long-filename1.txt long-long-filename2.txt long-long-filename3.txt
        pwd
        cat !ls:*

        ls long-long-filename1.txt long-long-filename2.txt long-long-filename3.txt
        pwd
        cat !ls:^

        ls long-long-filename1.txt long-long-filename2.txt long-long-filename3.txt
        pwd
        cat !ls:$

        :n1,n2s/word1/word2/g	n1 與 n2 為數字。在第 n1 與 n2 列之間尋找 word1 這個字串，並將該字串取代為 word2 ！舉例來說，在 100 到 200 列之間搜尋 vbird 並取代為 VBIRD 則：
        『:100,200s/vbird/VBIRD/g』。(常用)
        :1,$s/word1/word2/g	從第一列到最後一列尋找 word1 字串，並將該字串取代為 word2 ！(常用)
        :1,$s/word1/word2/gc	從第一列到最後一列尋找 word1 字串，並將該字串取代為 word2 ！且在取代前顯示提示字元給使用者確認 (confirm) 是否需要取代！(常用)

    >>  goto of c lang 
            get out of nested loop
            One good place to use a goto is in a procedure that can abort at several points, each of which requires various levels of cleanup    
        
    >>  eclipse 如何 auto 產生 makefile, makefile
        jserv ** 可以改變 struct, google unitest
        
    >>  typedef volatile unsigned long  vu32;
        #define M32(num) (*((vu16 *)(num))) of flash algorithm
        compiler time will take care those M32/M16/M8 things
        M32(0x20002000) = 0x12345678;  - will load 32bits and store to 0x20002000
        M16(0x20002004) = 0x12345678;  - only load 16bits LSB 0x5678 and store to 0x20002004
        
        
    >>  reference    
        int& getInt()
        {
           static int x = 4;
           return x;
        }
        int& x = getInt(); 

        This is also quite common when implementing Singleton pattern
        Class Singleton
        {
            public:
                static Singleton& instance()
                {
                    static Singleton instance;
                    return instance;
                };

            //protect:
                //Singleton();
         }
         Usage:
         Singleton& my_sing = Singleton::instance(); // Valid Singleton instance
         my_sing.printHello();  // "Hello"

         以上僅能創建一個 object, 但若不加 protect Singleton
         Singleton s1;
         Singleton s2; 可以造出二個不同的 singleton

    >>  static int variable of class , like a glabol varible 
        static int member function , can use to access static varible of class
         
    >>  lvalue
        1. ++x 是左值而 x++ 卻是右值
        2. int *ptr_val 若 *ptr_val 在等號左邊就是 lvalue, 右邊是 rvalue
        3. the unary '*' (dereference) operator takes an rvalue argument but produces an lvalue as a result
           Conversely, the unary address-of operator '&' takes an lvalue argument and produces an rvalue

           
    >>  function variable arguments - ellipsis
        va_list valist 
        va_start(valist, num)
        va_arg(valist, int)
        va_end(valist)
        
    >>  garbage collection howto?
        implement an counter to record the counter of object instance

    >>  print define value    
        #define XSTR(x) STR(x)
        #define STR(x) #x
        #pragma message "The value of ABC: " XSTR(__ARM_FEATURE_CMSE)
        
    >>  preprocessor is sequencial, so the header guard is to prevent the same .h from being included twice by the same .c file
        #ifndef B_H_
        #define B_H_
            happen here
        #endif /* B_H_ */
        ...
        #ifndef B_H_
        #define B_H_
            won't happen here
        #endif /* B_H_ */
        
    >>  static function vs inline function
        In a nutshell, if you use static, then taking the address of the function in different translation units will return different addresses 
       (because you're telling the compiler to generate a function in each TU), but if you use inline, they'll show the same address 
       (because you're defining one function, and just telling the compiler to merge the many definitions together)    

    >> strcat ( char *A, char *B) 將B加到A後面，因為不會自己alloc mem, A要有足夠size
        A = malloc (size), A = "Hello"　再 strcat (A, B) 這樣會有問題因為 A 沒有指向 malloc 的位址而是指向”Hello" 那
        用 strcpy (A, "Hello") 才是正解


    >> [A,B) from A up to, but not including, B 

    >>　string::npos <- means maximum allowable number of characters for a string object, it is one greater than the largest possible index and can be used to indicate failure to find a character or a string

    >>  cout << "test" << 88 ;  int to string?
        cout << 0x16; present in decimal?
        cout << -16
        均照 display
        
    >> return const ref: Max()
        return non-const ref: <<, =
        return object: arithmetic

    >> new & delete should be noticed that : copy constructor and assign operator can only assign pointer not deep copy
        so you have to pay attention and override copy constructor & assign operator
        
    >> function returning object will call copy constructor , but return reference won't
       

    >> if your class has a static data member whose value changes when new objects are created, you should 
        provide explicit copy constructor that handles the accounting.

    >>    (reference &) is refer to "int & xx = oo" take oo's address 
                     int rats = 101;
                     int * pt = &rats;
                     int & rodents = *pt;
                     int bunnies = 50;
                     pt = &bunnies;


    >> constructor order from base to derived
       destructor order from derived to base

    >> virtual inherit
        once the parent virtual, all its childs are virtual, even the prototype doesn't have virtual keyword
        if parent isn't virtual, child1 starts to virtual, childs after child1 are virtual

    >> allegiance of reference, must assign at the first stage, and can't modify later

    >> (self) createfilemapping
        CreateFileMapping 可以在不同 process 創建共享 share memory, 二個process要用同一個 m_tShareName
        去看二個 process 各自CreateFileMapping 回傳的 handle 值相同與否不能斷定是不是用到同一個 share memory 
        MapViewOfFile 傳回的值是各個 process 對照到的 logical address, 就算2個 process不同, 可能是 map to 同一塊 share memory
        CreateMutex 若沒有給名字, 可以達到同一個process各 thread 互斥. 若有給名字, 可以達到各 process 互斥.
        
        CICEGlobalMutex 中的 ShareArea 以 CICEGlobalData 為 template type
        CICEGlobalMutex 有	COneInstance2				m_OneMutex;	//Mutex for this one ICE
                            COneInstance				m_AllMutex;	//Mutex for all ICE
        
    >> vc++ 帶不出部份 .h file. 如 oneInstance.h

    >> struct FuncCaller in AGDI.cpp
        - seems to destruct AXF object, but don't know why don't use destructor of AXF
        - per experiment, CAXF_M0 and CAXF destructor will be call by sequence
        
    >> Containment, private inheritance, and protected inheritance are typically used to implement has-a relationships
        containment: class A contain class B, class A can use class B's public method. but program can't use object A to access B.
        A common way of describing this is to say that the A class acquires the implementation of its member objects but doesn’t inherit the interface.
        object A 本身並不具有 object B method
        inherit & containment 差在哪 - 都是acquires the implementation of its member objects but doesn’t inherit the interface 達到 "has-a" relationships, 功效一樣, 差在做法
        那是否private也可以用? - 需要B宣告A為 friend class 
        In general, you should use containment to model a has-a relationship. You should use private inheritance
        if the new class needs to access protected members in the original class or if it needs to redefine virtual functions.

    >> 記得ABC的 destructor 一定要是 virtual? -> virtual ~Device();

    >> 如何在 KEIL 塞入 assembly. e.g. BKPT, NOP

    >> not set DHCSR MASK INT means step and may step into ISR?

    >> floating point experiment in M451 

    >> ICE fw 的 Heap_Size 0x40 是否用來裝 m_pDevice = new(&m_device_buf) DeviceV6M;
        Stack_Size      EQU     0x00000100 - 屬 ZI_data
        DCD     SWDC_IRQHandler            - RO_data size is word
        Heap_Size       EQU     0x00000100 - change this value but nothing happen
        比對看看 ICE2 在 heap_size 有做什麼手腳?
        
    --------------------------------------------------------------------------------------------    
    <c++ note>
           
    C language 中的 static __inline
        static function: 只有同file內可以呼叫, 若加在 header file, compiler 必用此 inline function optimize
        inline 若沒有加static , 若在本檔以及別的檔都有定義 external inline function, 那有可能會參照二者之一
        refer to "C primer.pdf"

    const
        C language "const" default 是 external linkage, 所以在 A.h 加一個 const int A; 且A.h 被A.c and B.c include, 是無法編得過的
        上述若改成 static const int A; 則編得過
        C++ 把const 的linkage default 改成 static linkage, 所以在 A.h 寫 const int A=0; 可 build 得過, 這樣user 不用記要加static.
        記得, const define 要 initialize. 
        在c++也可以用extern override 掉 const 的internal linkage, 很特別的在extern 去init value. 如下寫法 extern const int states = 50; 但好像沒什麼好處
        KEIL 要用 C++, armcc 會根據是不是有 compile option --cpp 或是副檔名全都是 cpp , 就會直接用 c++ compile
        但中斷 function handler 要加 extern "C" {, 才 call 的到
      
        // in namespace or global scope
        int i; // extern by default
        const int ci; // c extern by default, c++ change to static by default for in header file
        extern const int eci; // explicitly extern
        static int si; // explicitly static

        // the same goes for functions (but there are no const functions)
        int foo(); // extern by default
        static int bar(); // explicitly static     

    macro:
    #define __glC(x) (*__gl_sym[__gl##x].f)


    typedef 解讀法 
    把定義中的 typedef 拿掉, 同時資料型態名稱換成變數的名稱, 就會比較容易理解. 例如: 把 typedef uint8_t Buffer[16]; 去掉 typedef, Buffer 換成變數名 xBuf, 變成 uint8_t xBuf[16];
        example:
        typedef uint8_t   Buffer[16];
        Buffer xBuf; 
        xBuf[0] = 3;
        xBuf[1] = 2;

    const int ** A;  解讀法
        right to left, pointer to pointer to const int
    int * const * A
        pointer to const pointer to int 
        
    inline function and macro 的差異, function 是傳值 macro 是替代 #define SQUARE(X) (X*X)
    a = SQUARE(5.0); is replaced by a = 5.0*5.0;
    b = SQUARE(4.5 + 7.5); is replaced by b = 4.5 + 7.5 * 4.5 + 7.5;
    d = SQUARE(c++); is replaced by d = c++*c++;
    Only the first example here works properly. You can improve matters with a liberal application of
    parentheses:
    #define SQUARE(X) ((X)*(X))
    Still, the problem remains that macros don’t pass by value. Even with this new definition,
    SQUARE(c++) increments c twice, but the inline square() function in Listing 8.1 evaluates c, passes
    that value to be squared, and then increments c once.


    struct 寫法
        1. 
        struct A{
        }a, b;
        a, b is struct of A
        struct A c; 
        
        2.
        typedef struct A{
        }AS;
        AS a;  
         
    function pointer:
        void custom_for_each( int *pArray, unsigned int size, int (*op)( int ) )
        custom_for_each( pArray, size, &power2 );
    使用 typedef 加強可讀性
        typedef int (*CustomOperator)( int );
        void custom_for_each( int *pArray, unsigned int size, CustomOperator op )
    Function Pointer 的陣列
        int (*op[10])( int );
        typedef int (*CustomOperator)( int );
        CustomOperator op[10];

    typedef CFlash_Mini51<CICE_Mini51<CICE_M0_Cache> > FLASH_T;    
        
    *  as "pointer to"   - always on the left side
    []  as "array of"   - always on the right side
    ()  as "function returning"  - always on the right side    

    儲存類別    關鍵字     宣告位置         持久性(Duration)  有效範圍(scope)
    自動變數    auto       函式內或區塊內   暫時              區域 Local
    暫存器變數  register   函式內或區塊內   暫時              區域 Local
    靜態變數    static     函式內或區塊內   persistence       區域 Local
    外部變數    extern     函式外面         persistence       Global(所有檔案)
    外部靜態    static     函式外面         persistence       Global(一個檔案) 


    Git初探之Fork及Branch
    剛接觸Git這套版本管理的solution。一開始對Fork和Branch的差別是什麼始終不太清楚，經過測試後，大致的心得如此。
    1.Fork會另外複製一個版本，這個版本也是一個完整的套件。
    2.官方說明文字裡指出，Fork主要是指要以其他人的套件為初始套件來開發時，或者要替他人的套件做出貢獻，也就是說通常是從其他Git帳號所擁有的套件複製而來的就是Fork。
    3.如果是自己的套件，正確的作法應使用branch
    4.Fork底下還可以有Branch，但沒有Branch底下還有Fork這種狀況。
    5.無論是Fork還是Branch的版本都可以合併至主要版本。唯一差別是Fork是向原作者送出merge的要求，尚需要原作者允許才可以合併，而branch因為是從自己的帳號分支出來的套件，所以不須另外允許

    __declspec, which specifies that an instance of a given type is to be stored with a Microsoft-specific storage-class attribute
    dllexport to export function for other application. dllimport is not necessary, if having it, compiler may improve performance
    DLL Implicitly/Explicit  Link


    The "right-left" rule is a completely regular rule for deciphering C declarations. It can also be useful in creating them.
        First, symbols. Read
            * as "pointer to" - always on the left side
            [] as "array of" - always on the right side
            () as "function returning" - always on the right side

        STEP 1
            Find the identifier. This is your starting point. Then say to yourself, "identifier is". You've started your declaration.
        STEP 2
            Look at the symbols on the right of the identifier. If, say, you find "()" there, then you know that this is the declaration for a function. So you would then have "identifier is function returning". Or if you found a "[]" there, you would say "identifier is array of". Continue right until you run out of symbols *OR* hit a *right* parenthesis ")". (If you hit a left parenthesis, that's the beginning of a () symbol, even if there is stuff in between the parentheses. More on that below.)
        STEP 3
            Look at the symbols to the left of the identifier. If it is not one of our symbols above (say, something like "int"), just say it. Otherwise, translate it into English using that table above. Keep going left until you run out of symbols *OR* hit a *left* parenthesis "("

        Illegal combinations include:
            []() - cannot have an array of functions
            ()() - cannot have a function that returns a function
            ()[] - cannot have a function that returns an array

    </c++ note>

          
            
    <solve>
        about the opcode, should check v7m document
        BL.W means what?
        .W means 32bits
    </solve>

    
    
    


    
