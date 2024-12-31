import { getInputStr } from "./helper";

function isSafe(report: number[]): boolean {
    if (report.length === 1)
        return true;
    let increasing: boolean = report[0] < report[1];
    for (let i = 0; i < report.length - 1; i++) {
        if (increasing && report[i] >= report[i + 1])
            return false;
        if (!increasing && report[i] <= report[i + 1])
            return false;
        const diff = Math.abs(report[i + 1] - report[i])
        if (diff < 1 || diff > 3)
            return false;
    }
    return true;
}

function isSafeWithRemoval(report: number[], index: number): boolean {
    const removedLevel = report.splice(index, 1);
    if (index === report.length + 1)
        return false;

    if (isSafe(report))
        return true;
    // insert removed level back to report
    report.splice(index, 0, ...removedLevel);
    return isSafeWithRemoval(report, index + 1);
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
            if (reportInt.length === 1 || isSafe(reportInt)) {
                safeReports += 1;
            } else {
                safeReports += isSafeWithRemoval(reportInt, 0) ? 1 : 0;
            }
        }
    }
    return safeReports;
}

async function main() {
    const inputStr = await getInputStr('inputs/d2p2.txt');
    const ans = solve(inputStr);
    console.log(ans);
}
main()