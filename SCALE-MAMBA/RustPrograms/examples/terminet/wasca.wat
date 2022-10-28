(module
 (type $i64_=>_none (func (param i64)))
 (type $none_=>_none (func))
 (type $i32_=>_none (func (param i32)))
 (type $none_=>_i64 (func (result i64)))
 (type $i64_=>_i64 (func (param i64) (result i64)))
 (type $i64_=>_f64 (func (param i64) (result f64)))
 (type $i64_i64_=>_f32 (func (param i64 i64) (result f32)))
 (type $f32_=>_f64 (func (param f32) (result f64)))
 (type $f64_f64_=>_f64 (func (param f64 f64) (result f64)))
 (type $f64_=>_none (func (param f64)))
 (type $none_=>_f64 (func (result f64)))
 (type $f64_=>_i64 (func (param f64) (result i64)))
 (type $f64_=>_f32 (func (param f64) (result f32)))
 (type $f32_i64_=>_none (func (param f32 i64)))
 (type $i64_=>_f32 (func (param i64) (result f32)))
 (type $i64_i64_i64_i64_=>_none (func (param i64 i64 i64 i64)))
 (import "env" "init_wasm_heap_memory" (func $init_wasm_heap_memory))
 (import "env" "__print_char_regint" (func $__print_char_regint (param i64)))
 (import "env" "__pushint" (func $__pushint (param i64)))
 (import "env" "__lf" (func $__lf (param i32)))
 (import "env" "__popint" (func $__popint (result i64)))
 (import "env" "__news" (func $__news (param i64) (result i64)))
 (import "env" "__print_int" (func $__print_int (param i64)))
 (import "env" "__convregsreg" (func $__convregsreg (param i64) (result f64)))
 (import "env" "__private_input" (func $__private_input (param i64 i64) (result f32)))
 (import "env" "__convsintsreg" (func $__convsintsreg (param f32) (result f64)))
 (import "env" "__addsint" (func $__addsint (param f64 f64) (result f64)))
 (import "env" "__pushsint" (func $__pushsint (param f64)))
 (import "env" "__gc" (func $__gc (param i32)))
 (import "env" "__popsint" (func $__popsint (result f64)))
 (import "env" "__opensint" (func $__opensint (param f64) (result i64)))
 (import "env" "__convsregsint" (func $__convsregsint (param f64) (result f32)))
 (import "env" "__stmsi" (func $__stmsi (param f32 i64)))
 (import "env" "__ldmsi" (func $__ldmsi (param i64) (result f32)))
 (import "env" "__mprivate_output" (func $__mprivate_output (param i64 i64 i64 i64)))
 (import "env" "__deletes" (func $__deletes (param i64)))
 (global $global$1 i32 (i32.const 1048576))
 (global $global$2 i32 (i32.const 1048576))
 (memory $0 16)
 (export "memory" (memory $0))
 (export "main" (func $main))
 (export "__data_end" (global $global$1))
 (export "__heap_base" (global $global$2))
 (func $main
  (local $0 i64)
  (local $1 i64)
  (local $2 i64)
  (local $3 i64)
  (call $init_wasm_heap_memory)
  (call $__print_char_regint
   (i64.const 10)
  )
  (call $__print_char_regint
   (i64.const 35)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 77)
  )
  (call $__print_char_regint
   (i64.const 101)
  )
  (call $__print_char_regint
   (i64.const 97)
  )
  (call $__print_char_regint
   (i64.const 110)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 65)
  )
  (call $__print_char_regint
   (i64.const 108)
  )
  (call $__print_char_regint
   (i64.const 103)
  )
  (call $__print_char_regint
   (i64.const 111)
  )
  (call $__print_char_regint
   (i64.const 114)
  )
  (call $__print_char_regint
   (i64.const 105)
  )
  (call $__print_char_regint
   (i64.const 116)
  )
  (call $__print_char_regint
   (i64.const 104)
  )
  (call $__print_char_regint
   (i64.const 109)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 102)
  )
  (call $__print_char_regint
   (i64.const 111)
  )
  (call $__print_char_regint
   (i64.const 114)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 84)
  )
  (call $__print_char_regint
   (i64.const 69)
  )
  (call $__print_char_regint
   (i64.const 82)
  )
  (call $__print_char_regint
   (i64.const 77)
  )
  (call $__print_char_regint
   (i64.const 73)
  )
  (call $__print_char_regint
   (i64.const 78)
  )
  (call $__print_char_regint
   (i64.const 69)
  )
  (call $__print_char_regint
   (i64.const 84)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 40)
  )
  (call $__print_char_regint
   (i64.const 101)
  )
  (call $__print_char_regint
   (i64.const 97)
  )
  (call $__print_char_regint
   (i64.const 115)
  )
  (call $__print_char_regint
   (i64.const 121)
  )
  (call $__print_char_regint
   (i64.const 32)
  )
  (call $__print_char_regint
   (i64.const 105)
  )
  (call $__print_char_regint
   (i64.const 110)
  )
  (call $__print_char_regint
   (i64.const 112)
  )
  (call $__print_char_regint
   (i64.const 117)
  )
  (call $__print_char_regint
   (i64.const 116)
  )
  (call $__print_char_regint
   (i64.const 41)
  )
  (call $__print_char_regint
   (i64.const 10)
  )
  (call $__print_char_regint
   (i64.const 10)
  )
  (call $__pushint
   (i64.const 5)
  )
  (call $__lf
   (i32.const 125)
  )
  (local.set $3
   (call $__popint)
  )
  (local.set $0
   (call $__news
    (i64.const 1)
   )
  )
  (loop $label$1
   (call $__print_int
    (local.get $1)
   )
   (call $__print_char_regint
    (i64.const 10)
   )
   (call $__pushsint
    (call $__addsint
     (call $__addsint
      (call $__addsint
       (call $__addsint
        (call $__addsint
         (call $__convregsreg
          (i64.const 0)
         )
         (call $__convsintsreg
          (call $__private_input
           (i64.const 1)
           (i64.const 0)
          )
         )
        )
        (call $__convsintsreg
         (call $__private_input
          (i64.const 2)
          (i64.const 0)
         )
        )
       )
       (call $__convsintsreg
        (call $__private_input
         (i64.const 3)
         (i64.const 0)
        )
       )
      )
      (call $__convsintsreg
       (call $__private_input
        (i64.const 4)
        (i64.const 0)
       )
      )
     )
     (call $__convsintsreg
      (call $__private_input
       (i64.const 5)
       (i64.const 0)
      )
     )
    )
   )
   (call $__gc
    (i32.const 125)
   )
   (call $__pushint
    (call $__opensint
     (call $__popsint)
    )
   )
   (call $__pushint
    (local.get $3)
   )
   (call $__lf
    (i32.const 122)
   )
   (call $__pushsint
    (call $__convregsreg
     (call $__popint)
    )
   )
   (call $__gc
    (i32.const 124)
   )
   (call $__stmsi
    (call $__convsregsint
     (call $__popsint)
    )
    (local.get $0)
   )
   (local.set $2
    (call $__news
     (i64.const 1)
    )
   )
   (call $__stmsi
    (call $__ldmsi
     (local.get $0)
    )
    (local.get $2)
   )
   (call $__mprivate_output
    (local.get $2)
    (i64.const 1)
    (i64.const 0)
    (i64.const 0)
   )
   (call $__deletes
    (local.get $2)
   )
   (br_if $label$1
    (i64.ne
     (local.tee $1
      (i64.add
       (local.get $1)
       (i64.const 1)
      )
     )
     (i64.const 4881)
    )
   )
  )
  (call $__deletes
   (local.get $0)
  )
 )
 ;; custom section ".debug_aranges", size 0, contents: ""
 ;; custom section "producers", size 75
 ;; features section: simd
)
