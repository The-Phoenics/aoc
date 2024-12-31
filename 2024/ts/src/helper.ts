const { readFile } = require('node:fs/promises')

export async function getInputStr(filepath: string) {
    let inputStr;
    try {
        inputStr = await readFile(filepath, { encoding: 'utf8' })
    } catch (err) {
        throw err;
    }
    return inputStr;
}
