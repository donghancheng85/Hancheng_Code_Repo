pub fn exercise3()
{
    println!("exercise3 function...");
    // multiple variables
    let lhx: i32 = 5 + 3;
    let lhy: i32 = 6 - 2;
    let rhz: i32 = lhx * lhy;
    println!("exercise3 multiple variables ans: result = {}", rhz);

    // single varialbe
    let single_var: i32 = (5 + 3) * (6 - 2);
    println!("exercise3 single variables ans:   result = {}", single_var);

    // no varialbe
    println!("exercise3 no variables ans:       result = {}", (5 + 3) * (6 - 2));
}