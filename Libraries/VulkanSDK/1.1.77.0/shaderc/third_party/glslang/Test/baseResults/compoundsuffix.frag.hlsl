compoundsuffix.frag.hlsl
// Module Version 10000
// Generated by (magic number): 80006
// Id's are bound by 22

                              Capability Shader
               1:             ExtInstImport  "GLSL.std.450"
                              MemoryModel Logical GLSL450
                              EntryPoint Fragment 4  "main" 20
                              ExecutionMode 4 OriginUpperLeft
                              Source HLSL 500
                              Name 4  "main"
                              Name 11  "@main(vf4;"
                              Name 10  "fragColor"
                              Name 15  "fragColor"
                              Name 16  "param"
                              Name 20  "fragColor"
                              Decorate 20(fragColor) Location 0
               2:             TypeVoid
               3:             TypeFunction 2
               6:             TypeFloat 32
               7:             TypeVector 6(float) 4
               8:             TypePointer Function 7(fvec4)
               9:             TypeFunction 2 8(ptr)
              13:    6(float) Constant 1065353216
              14:    7(fvec4) ConstantComposite 13 13 13 13
              19:             TypePointer Output 7(fvec4)
   20(fragColor):     19(ptr) Variable Output
         4(main):           2 Function None 3
               5:             Label
   15(fragColor):      8(ptr) Variable Function
       16(param):      8(ptr) Variable Function
              17:           2 FunctionCall 11(@main(vf4;) 16(param)
              18:    7(fvec4) Load 16(param)
                              Store 15(fragColor) 18
              21:    7(fvec4) Load 15(fragColor)
                              Store 20(fragColor) 21
                              Return
                              FunctionEnd
  11(@main(vf4;):           2 Function None 9
   10(fragColor):      8(ptr) FunctionParameter
              12:             Label
                              Store 10(fragColor) 14
                              Return
                              FunctionEnd
