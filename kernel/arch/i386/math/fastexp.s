# Thanks /u/FUZxxl, always saving the day
        .text
        .global fastexp
        .type fastexp,@function
        .align 4

fastexp:
        fldt 4(%esp)            # x
        fldl2e                  # log2(e) x
        fmulp                   # x' (= log2(e) * x)
        fld %st(0)              # x' x'
        frndint                 # round(x') x'
        fsubr %st(0),%st(1)     # round(x') x'-round(x')
        fxch                    # x'-round(x') round(x')
        f2xm1                   # 2^(x'-round(x'))-1 round(x')
        fld1                    # 1 2^(x'-round(x'))-1 round(x')
        faddp                   # 2^(x'-round(x')) round(x')
        fscale                  # 2^(x'-round(x'))*2^round(x') (= 2^x' = e^x) round(x')
        ffree %st(1)            # e^x
        ret
.size fastexp,.-fastexp
