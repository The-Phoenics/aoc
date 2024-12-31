import { getInputStr } from "./helper"

const regex = new RegExp("[0-9]{0,4},[0-9]{0,4}[)]")

function solveLine(line: string): number {
    let ans: number = 0;
    const splitStr: string = "mul(";
    const firstPass: string[] = line.split(splitStr);
    if (firstPass.length < 2)
        return 0;
    firstPass.forEach((s) => {
        console.log(s)
        if (regex.test(s)) {
            const split = s.split(")")[0].split(",")
            console.log(split, "\n")
            let num1, num2;
            try {
                num1 = Number.parseInt(split[0]);
                num2 = Number.parseInt(split[1]);
            } catch(err) {
                throw err
            }
            ans += num1 * num2;
        }
    })
    return ans;
}

function solve(inputStr: string): number {
    const inputArray = inputStr.split("\n");
    let result: number = 0;
    for (let line of inputArray) {
        result += solveLine(line);
    }
    return result;
}

async function main() {
    const inputStr = await getInputStr('inputs/d3p1.txt');
    const f = 'xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))';
    const ans = solve(inputStr);
    console.log(ans);
}
main()