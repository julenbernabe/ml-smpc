// Copyright (c) 2022, Tecnalia RI, Derio, Bizkaia.
// Julen Bernabe Rodriguez

#![no_std]
#![no_main]
#![feature(const_evaluatable_checked)]


use scale_std::ieee::ClearIEEE;
use scale_std::ieee::SecretIEEE;
use scale_std::array::Array;
use scale_std::slice::Slice;

#[scale::main(KAPPA = 40)]
#[inline(always)]
fn main() {
    println!("\n# Mean Algorithm for TERMINET (easy input)\n");

//                                      CAMBIAR ESTAS VARIABLES PARA N NODOS (CONTANDO DEVELOPER)
//  #############################################################################################################################
/*  #                                                                                                                           #
    #*/ const N_PLAYERS: u64 = 5;                           /*CAMBIAR ESTA VARIABLE SEGÚN NÚMERO DE NODOS EDGE                  #
    #*/ let nrows = 4881;                                   /*CAMBIAR ESTA VARIABLE PARA QUE PRODUCTO CON NCOLS = FILAS EN DOC  #
    #*/ const NCOLS: u64 = 1;                               /*CAMBIAR ESTA VARIABLE PARA QUE PRODUCTO CON NROWS = FILAS EN DOC  #
    #*/ let prog = 1;                                       /*CAMBIAR ESTA VARIABLE SEGÚN ESTADÍSTICO A CALCULAR                #
    #                                                                                                                           #
    #############################################################################################################################

    RECORDAR QUE:
        - PROG = 1: Se ejecuta media por redondeo.
        - PROG = 2: Se ejecuta media por truncamiento.
        - PROG = 3: Se ejecuta mediana/moda para binarios.
*/

    let n_players = N_PLAYERS as i64;
    let n_players_ieee = ClearIEEE::from(n_players);
    let mut mean: Array<SecretModp, NCOLS> = Array::uninitialized();

    if prog == 1 {
        for i in 0..nrows {
            println!(i);
            for j in 0..NCOLS {
                let sum = SecretIEEE::from(sum(N_PLAYERS));
                let partial = SecretModp::from(SecretI64::from(SecretIEEE::from(sum.reveal() / n_players_ieee)));
                mean.set(j, &partial);
            }
            mean.clone().private_output(0,0);
        }
    }
    if prog == 2 {
        for i in 0..nrows {
            println!(i);
            for j in 0..NCOLS {
                let sum = sum(N_PLAYERS);
                let partial = SecretModp::from(SecretI64::from(sum.reveal() / n_players));
                mean.set(j, &partial);
            }
            mean.clone().private_output(0,0);
        }
    }
    if prog == 3 {
        for i in 0..nrows {
            println!(i);
            for j in 0..NCOLS {
                let partial = agg(N_PLAYERS);
                mean.set(j, &partial);
            }
            mean.clone().private_output(0,0);
        }
        
    }
    
}

fn sum(n_players: u64) -> SecretI64 {
    let mut sum = SecretI64::from(0);
    for k in 1..n_players + 1 {
        sum = sum + SecretI64::from(SecretModp::private_input(k as i64, 0));
    }
    return sum;
}

fn agg(n_players: u64) -> SecretModp {
    let mut sum: Slice<SecretI64> = Slice::uninitialized(n_players);
    let mut input = SecretI64::from(0);
    for k in 1..n_players +1 {
        input = SecretI64::from(SecretModp::private_input(k as i64, 0));
        sum.set(k-1, &input);
    }
    return mode_bin(sum.clone(), n_players as i64);
}

fn mode_bin(a: Slice<SecretI64>, n: i64) -> SecretModp {
    let zero = SecretI64::from(0);
    let mut zeros = i64::from(0);
    for i in 0..n {
        let ai = *a.get_unchecked(i as u64);
        let iszero = i64::from(SecretModp::from(zero.eq(ai)).reveal());
        if iszero == 1 {
            zeros = zeros + 1;
        }
    }
    let ones = n - zeros;
    if ones > zeros {
        return SecretModp::from(1);
    } else {
        return SecretModp::from(0);
    }
}
