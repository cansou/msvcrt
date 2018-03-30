####
# makefile.inc - Included makefile for VCRT build process
#
#   Copyright (c) Microsoft Corporation. All rights reserved.
#
#
###############################################################################

PREOBJDIR = $(CPUDIR)\$(BLD_MODEL)_lib

# These are the prebuilt objects which are static link components in the
# MSVCRXX[D].DLL implib

# Here is the target for building LIBC{,D} / LIBCMT{,D} / MSVCRT{,D}.LIB

all: \
!if "$(BLD_DLL)"=="1"
        $(OBJDIR)\dllstuff.lib \
!endif
        $(OBJDIR)\heap.lib     \
        $(OBJDIR)\misc.lib     \
!if "$(RTC)"=="YES"
        $(OBJDIR)\rtc.lib      \
!endif
        $(OBJDIR)\startup.lib  
   

DLLSTUFF_OBJECTS = \
        $(OBJDIR)\atonexit.obj \
        $(OBJDIR)\crtexe.obj   \
        $(OBJDIR)\crtmanifestrtm.obj   \
        $(OBJDIR)\cinitexe.obj \
        $(OBJDIR)\dllargv.obj  \
        $(OBJDIR)\merr.obj     \
        $(OBJDIR)\natstart.obj \
        $(OBJDIR)\unhandld.obj \
        $(OBJDIR)\wildcard.obj \
        $(OBJDIR)\xtxtmode.obj \
        $(OBJDIR)\xthdloc.obj \
        $(OBJDIR)\xncommod.obj \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\adjustfd.obj \
!endif


HEAP_OBJECTS = \
        $(OBJDIR)\_newmode.obj 

MISC_OBJECTS = \
!if "$(TARGET_CPU)"=="i386"
        $(OBJDIR)\chandler4gs.obj\
        $(OBJDIR)\secchk.obj   \
!endif
        $(OBJDIR)\gs_cookie.obj \
        $(OBJDIR)\gs_report.obj \
        $(OBJDIR)\gs_support.obj \
        $(OBJDIR)\pesect.obj   \

STARTUP_OBJECTS = \
!if "$(TARGET_CPU)" == "i386"
        $(OBJDIR)\fp8.obj      \
!endif

$(OBJDIR)\dllstuff.lib: $(DLLSTUFF_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(DLLSTUFF_OBJECTS: =^
)
<<keep


$(OBJDIR)\heap.lib: $(HEAP_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(HEAP_OBJECTS: =^
)
<<keep


$(OBJDIR)\helper.lib: $(HELPER_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(HELPER_OBJECTS: =^
)
<<keep


$(OBJDIR)\misc.lib: $(MISC_OBJECTS)
    $(LIB) -out:$@ @<<$*.rsp
$(MISC_OBJECTS: =^
)
<<keep


!if "$(BLD_DLL)"=="1"
$(OBJDIR)\startup.lib: $(STARTUP_OBJECTS)
!else
$(OBJDIR)\startup.lib: $(STARTUP_OBJECTS)
!endif
    $(LIB) -out:$@ @<<$*.rsp
$(STARTUP_OBJECTS: =^
)
<<keep

!if "$(RTC)"=="YES"
$(OBJDIR)\rtc.lib: $(PREOBJDIR)\rtc.lib
        copy $(PREOBJDIR)\rtc.lib $@
!endif

# !if "$(BLD_SYSCRT)" != "1"

$(OBJDIR)\tncleanup.obj: $(PREOBJDIR)\tncleanup.obj
        copy $(PREOBJDIR)\tncleanup.obj $@

$(OBJDIR)\oldexcpt.obj: $(PREOBJDIR)\oldexcpt.obj
        copy $(PREOBJDIR)\oldexcpt.obj $@

$(OBJDIR)\sehprolg.obj: $(PREOBJDIR)\sehprolg.obj
        copy $(PREOBJDIR)\sehprolg.obj $@

$(OBJDIR)\sehprolg4.obj: $(PREOBJDIR)\sehprolg4.obj
        copy $(PREOBJDIR)\sehprolg4.obj $@

$(OBJDIR)\sehprolg4gs.obj: $(PREOBJDIR)\sehprolg4gs.obj
        copy $(PREOBJDIR)\sehprolg4gs.obj $@

$(OBJDIR)\sehsupp.obj: $(PREOBJDIR)\sehsupp.obj
        copy $(PREOBJDIR)\sehsupp.obj $@

$(OBJDIR)\calldtor.obj: $(PREOBJDIR)\calldtor.obj
        copy $(PREOBJDIR)\calldtor.obj $@

$(OBJDIR)\setjmp.obj: $(PREOBJDIR)\setjmp.obj
        copy $(PREOBJDIR)\setjmp.obj $@

!if "$(TARGET_CPU)" == "i386"

$(OBJDIR)\atlssup.obj: $(PREOBJDIR)\atlssup.obj
        copy $(PREOBJDIR)\atlssup.obj $@

$(OBJDIR)\bsku.obj: $(PREOBJDIR)\bsku.obj
        copy $(PREOBJDIR)\bsku.obj $@

$(OBJDIR)\chandler4.obj: $(PREOBJDIR)\chandler4.obj
        copy $(PREOBJDIR)\chandler4.obj $@

$(OBJDIR)\chandler4gs.obj: $(PREOBJDIR)\chandler4gs.obj
        copy $(PREOBJDIR)\chandler4gs.obj $@

$(OBJDIR)\ehprolg2.obj: $(PREOBJDIR)\ehprolg2.obj
        copy $(PREOBJDIR)\ehprolg2.obj $@

$(OBJDIR)\ehprolg3.obj: $(PREOBJDIR)\ehprolg3.obj
        copy $(PREOBJDIR)\ehprolg3.obj $@

$(OBJDIR)\ehprolg3a.obj: $(PREOBJDIR)\ehprolg3a.obj
        copy $(PREOBJDIR)\ehprolg3a.obj $@

$(OBJDIR)\ehprolog.obj: $(PREOBJDIR)\ehprolog.obj
        copy $(PREOBJDIR)\ehprolog.obj $@

$(OBJDIR)\eh3valid.obj: $(PREOBJDIR)\eh3valid.obj
        copy $(PREOBJDIR)\eh3valid.obj $@

$(OBJDIR)\exsup.obj: $(PREOBJDIR)\exsup.obj
        copy $(PREOBJDIR)\exsup.obj $@

$(OBJDIR)\exsup2.obj: $(PREOBJDIR)\exsup2.obj
        copy $(PREOBJDIR)\exsup2.obj $@

$(OBJDIR)\exsup3.obj: $(PREOBJDIR)\exsup3.obj
        copy $(PREOBJDIR)\exsup3.obj $@

$(OBJDIR)\exsup4.obj: $(PREOBJDIR)\exsup4.obj
        copy $(PREOBJDIR)\exsup4.obj $@

$(OBJDIR)\cpu_disp.obj: $(PREOBJDIR)\cpu_disp.obj
        copy $(PREOBJDIR)\cpu_disp.obj $@

$(OBJDIR)\ftol2.obj: $(PREOBJDIR)\ftol2.obj
        copy $(PREOBJDIR)\ftol2.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

$(OBJDIR)\memcmp.obj: $(PREOBJDIR)\memcmp.obj
        copy $(PREOBJDIR)\memcmp.obj $@

$(OBJDIR)\p4_memcpy.obj: $(PREOBJDIR)\p4_memcpy.obj
        copy $(PREOBJDIR)\p4_memcpy.obj $@

$(OBJDIR)\p4_memset.obj: $(PREOBJDIR)\p4_memset.obj
        copy $(PREOBJDIR)\p4_memset.obj $@

$(OBJDIR)\setjmp3.obj: $(PREOBJDIR)\setjmp3.obj
        copy $(PREOBJDIR)\setjmp3.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

########
#
# These objects can be built from (assembler) source by editing
# makefile.sub so that the symbol BLD_ASM is set to the value 1.
# To assembler these objects, you must have MASM 6.11a or later.
#
########

!if "$(BLD_ASM)"=="0"

$(OBJDIR)\alloca16.obj: $(PREOBJDIR)\alloca16.obj
        copy $(PREOBJDIR)\alloca16.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\dllsupp.obj: $(PREOBJDIR)\dllsupp.obj
        copy $(PREOBJDIR)\dllsupp.obj $@

$(OBJDIR)\enable.obj: $(PREOBJDIR)\enable.obj
        copy $(PREOBJDIR)\enable.obj $@

$(OBJDIR)\inp.obj: $(PREOBJDIR)\inp.obj
        copy $(PREOBJDIR)\inp.obj $@

$(OBJDIR)\lldiv.obj: $(PREOBJDIR)\lldiv.obj
        copy $(PREOBJDIR)\lldiv.obj $@

$(OBJDIR)\lldvrm.obj: $(PREOBJDIR)\lldvrm.obj
        copy $(PREOBJDIR)\lldvrm.obj $@

$(OBJDIR)\llmul.obj: $(PREOBJDIR)\llmul.obj
        copy $(PREOBJDIR)\llmul.obj $@

$(OBJDIR)\llrem.obj: $(PREOBJDIR)\llrem.obj
        copy $(PREOBJDIR)\llrem.obj $@

$(OBJDIR)\llshl.obj: $(PREOBJDIR)\llshl.obj
        copy $(PREOBJDIR)\llshl.obj $@

$(OBJDIR)\llshr.obj: $(PREOBJDIR)\llshr.obj
        copy $(PREOBJDIR)\llshr.obj $@

$(OBJDIR)\memccpy.obj: $(PREOBJDIR)\memccpy.obj
        copy $(PREOBJDIR)\memccpy.obj $@

$(OBJDIR)\memchr.obj: $(PREOBJDIR)\memchr.obj
        copy $(PREOBJDIR)\memchr.obj $@

$(OBJDIR)\memcpy.obj: $(PREOBJDIR)\memcpy.obj
        copy $(PREOBJDIR)\memcpy.obj $@

$(OBJDIR)\_memicmp.obj: $(PREOBJDIR)\_memicmp.obj
        copy $(PREOBJDIR)\_memicmp.obj $@

$(OBJDIR)\memmove.obj: $(PREOBJDIR)\memmove.obj
        copy $(PREOBJDIR)\memmove.obj $@

$(OBJDIR)\memset.obj: $(PREOBJDIR)\memset.obj
        copy $(PREOBJDIR)\memset.obj $@

$(OBJDIR)\outp.obj: $(PREOBJDIR)\outp.obj
        copy $(PREOBJDIR)\outp.obj $@

$(OBJDIR)\strcat.obj: $(PREOBJDIR)\strcat.obj
        copy $(PREOBJDIR)\strcat.obj $@

$(OBJDIR)\strchr.obj: $(PREOBJDIR)\strchr.obj
        copy $(PREOBJDIR)\strchr.obj $@

$(OBJDIR)\strcmp.obj: $(PREOBJDIR)\strcmp.obj
        copy $(PREOBJDIR)\strcmp.obj $@

$(OBJDIR)\strcspn.obj: $(PREOBJDIR)\strcspn.obj
        copy $(PREOBJDIR)\strcspn.obj $@

$(OBJDIR)\strlen.obj: $(PREOBJDIR)\strlen.obj
        copy $(PREOBJDIR)\strlen.obj $@

$(OBJDIR)\strncat.obj: $(PREOBJDIR)\strncat.obj
        copy $(PREOBJDIR)\strncat.obj $@

$(OBJDIR)\strncpy.obj: $(PREOBJDIR)\strncpy.obj
        copy $(PREOBJDIR)\strncpy.obj $@

$(OBJDIR)\_strnicm.obj: $(PREOBJDIR)\_strnicm.obj
        copy $(PREOBJDIR)\_strnicm.obj $@

$(OBJDIR)\strnset.obj: $(PREOBJDIR)\strnset.obj
        copy $(PREOBJDIR)\strnset.obj $@

$(OBJDIR)\strpbrk.obj: $(PREOBJDIR)\strpbrk.obj
        copy $(PREOBJDIR)\strpbrk.obj $@

$(OBJDIR)\strrchr.obj: $(PREOBJDIR)\strrchr.obj
        copy $(PREOBJDIR)\strrchr.obj $@

$(OBJDIR)\strrev.obj: $(PREOBJDIR)\strrev.obj
        copy $(PREOBJDIR)\strrev.obj $@

$(OBJDIR)\strset.obj: $(PREOBJDIR)\strset.obj
        copy $(PREOBJDIR)\strset.obj $@

$(OBJDIR)\strspn.obj: $(PREOBJDIR)\strspn.obj
        copy $(PREOBJDIR)\strspn.obj $@

$(OBJDIR)\strstr.obj: $(PREOBJDIR)\strstr.obj
        copy $(PREOBJDIR)\strstr.obj $@

$(OBJDIR)\ulldiv.obj: $(PREOBJDIR)\ulldiv.obj
        copy $(PREOBJDIR)\ulldiv.obj $@

$(OBJDIR)\ulldvrm.obj: $(PREOBJDIR)\ulldvrm.obj
        copy $(PREOBJDIR)\ulldvrm.obj $@

$(OBJDIR)\ullrem.obj: $(PREOBJDIR)\ullrem.obj
        copy $(PREOBJDIR)\ullrem.obj $@

$(OBJDIR)\ullshr.obj    : $(PREOBJDIR)\ullshr.obj
        copy $(PREOBJDIR)\ullshr.obj $@

!endif # BLD_ASM==0
!endif # TARGET_CPU == i386

!if "$(TARGET_CPU)" == "IA64"

$(OBJDIR)\chandler.obj: $(PREOBJDIR)\chandler.obj
        copy $(PREOBJDIR)\chandler.obj $@

$(OBJDIR)\cinitone.obj: $(PREOBJDIR)\cinitone.obj
        copy $(PREOBJDIR)\cinitone.obj $@

$(OBJDIR)\gshandler.obj: $(PREOBJDIR)\gshandler.obj
        copy $(PREOBJDIR)\gshandler.obj $@

$(OBJDIR)\gshandlereh.obj: $(PREOBJDIR)\gshandlereh.obj
        copy $(PREOBJDIR)\gshandlereh.obj $@

$(OBJDIR)\gshandlerseh.obj: $(PREOBJDIR)\gshandlerseh.obj
        copy $(PREOBJDIR)\gshandlerseh.obj $@

$(OBJDIR)\jmpuwind.obj: $(PREOBJDIR)\jmpuwind.obj
        copy $(PREOBJDIR)\jmpuwind.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\miscs.obj: $(PREOBJDIR)\miscs.obj
        copy $(PREOBJDIR)\miscs.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

$(OBJDIR)\strcat.obj: $(PREOBJDIR)\strcat.obj
        copy $(PREOBJDIR)\strcat.obj $@

$(OBJDIR)\strcpy.obj: $(PREOBJDIR)\strcpy.obj
        copy $(PREOBJDIR)\strcpy.obj $@

$(OBJDIR)\strcmp.obj: $(PREOBJDIR)\strcmp.obj
        copy $(PREOBJDIR)\strcmp.obj $@

$(OBJDIR)\strlen.obj: $(PREOBJDIR)\strlen.obj
        copy $(PREOBJDIR)\strlen.obj $@

$(OBJDIR)\memcmp.obj: $(PREOBJDIR)\memcmp.obj
        copy $(PREOBJDIR)\memcmp.obj $@

$(OBJDIR)\memcpy.obj: $(PREOBJDIR)\memcpy.obj
        copy $(PREOBJDIR)\memcpy.obj $@

$(OBJDIR)\memcpyi.obj: $(PREOBJDIR)\memcpyi.obj
        copy $(PREOBJDIR)\memcpyi.obj $@

$(OBJDIR)\memmove.obj: $(PREOBJDIR)\memmove.obj
        copy $(PREOBJDIR)\memmove.obj $@

$(OBJDIR)\memset.obj: $(PREOBJDIR)\memset.obj
        copy $(PREOBJDIR)\memset.obj $@

$(OBJDIR)\memseti.obj: $(PREOBJDIR)\memseti.obj
        copy $(PREOBJDIR)\memseti.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

!endif
!if "$(TARGET_CPU)"=="AMD64"
$(OBJDIR)\jmpuwind.obj: $(PREOBJDIR)\jmpuwind.obj
        copy $(PREOBJDIR)\jmpuwind.obj $@

$(OBJDIR)\longjmp.obj: $(PREOBJDIR)\longjmp.obj
        copy $(PREOBJDIR)\longjmp.obj $@

$(OBJDIR)\setjmpex.obj: $(PREOBJDIR)\setjmpex.obj
        copy $(PREOBJDIR)\setjmpex.obj $@

$(OBJDIR)\amdsecgs.obj: $(PREOBJDIR)\amdsecgs.obj
        copy $(PREOBJDIR)\amdsecgs.obj $@

$(OBJDIR)\chandler.obj: $(PREOBJDIR)\chandler.obj
        copy $(PREOBJDIR)\chandler.obj $@

$(OBJDIR)\chkstk.obj: $(PREOBJDIR)\chkstk.obj
        copy $(PREOBJDIR)\chkstk.obj $@

$(OBJDIR)\chkstk2.obj: $(PREOBJDIR)\chkstk2.obj
        copy $(PREOBJDIR)\chkstk2.obj $@

$(OBJDIR)\gshandler.obj: $(PREOBJDIR)\gshandler.obj
        copy $(PREOBJDIR)\gshandler.obj $@

$(OBJDIR)\gshandlereh.obj: $(PREOBJDIR)\gshandlereh.obj
        copy $(PREOBJDIR)\gshandlereh.obj $@

$(OBJDIR)\gshandlerseh.obj: $(PREOBJDIR)\gshandlerseh.obj
        copy $(PREOBJDIR)\gshandlerseh.obj $@

$(OBJDIR)\matherr.obj: $(PREOBJDIR)\matherr.obj
        copy $(PREOBJDIR)\matherr.obj $@

!endif
