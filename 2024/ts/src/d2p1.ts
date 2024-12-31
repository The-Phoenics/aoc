import { getInputStr } from "./helper";

function isSafe(report: number[]): number {
    // 1 for safe, 0 for unsafe report
    if (report.length === 1)
        return 1;
    let increasing: boolean = report[0] < report[1];
    for (let i = 0; i < report.length - 1; i++) {
        if (increasing && report[i] >= report[i + 1])
            return 0;
        if (!increasing && report[i] <= report[i + 1])
            return 0;
        const diff = Math.abs(report[i + 1] - report[i])
        if (diff < 1 || diff > 3)
            return 0;
    }
    return 1;
}

function solve(inputStr: string) {
    let safeReports: number = 0; 
    const reports: string[] = inputStr.split('\n');
    for (let report of reports) {
        if (report !== "") {
            const levels: string[] = report.split(" ");
            let reportInt: number[] = [];
            for (let level of levels) {
                reportInt.push(parseInt(level))
            }
            safeReports += isSafe(reportInt);
        }
    }
    return safeReports;
}

async function main() {
    const inputStr = await getInputStr('inputs/d2p1.txt');
    const ans = solve(inputStr);
    console.log(ans);
}
main()