    vs_2_0
    def c4, 3, 0, 0, 0
    dcl_position v0
    dcl_texcoord v1
    dcl_blendindices v2
    dcl_blendweight v3
    dp4 oT0.x, v1, c11
    dp4 oT0.y, v1, c12
    frc r0.xy, v2
    add r0.xy, -r0, v2
    mul r0.xy, r0, c4.x
    mova a0.xy, r0.yxzw
    mul r0, v3.y, c29[a0.x]
    mad r0, c29[a0.y], v3.x, r0
    dp4 r0.x, v0, r0
    mul r1, v3.y, c30[a0.x]
    mul r2, v3.y, c31[a0.x]
    mad r2, c31[a0.y], v3.x, r2
    mad r1, c30[a0.y], v3.x, r1
    dp4 r0.y, v0, r1
    dp4 r0.z, v0, r2
    mov r0.w, v1.w
    dp4 r1.z, r0, c2
    mul oT1.z, r1.z, c229.x
    dp4 r1.x, r0, c0
    dp4 r1.y, r0, c1
    dp4 r1.w, r0, c3
    mov oPos, r1
    mov oT1.xyw, r1
    mov oT2, c4.y
    mov oT3.xyz, c4.y
    mov oT4.xyz, c4.y
    mov oT5.xyz, c4.y

// approximately 27 instruction slots used