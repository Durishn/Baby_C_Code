import Foundation

let ALGLOOPNUM = 50

func quicksortHelper(inout alist: [Int], algNum: Int){

    var listBuff = alist
    var timeList = [Double]()
    var timeAv = Double()

    for i in 0..<algNum {

        listBuff = alist

        let t2 = CFAbsoluteTimeGetCurrent()

        quicksort(&listBuff, first: 0, last: alist.count-1)

        timeList.append(CFAbsoluteTimeGetCurrent() - t2)
        timeAv += timeList[i];

        print("Algorithm Time: ", timeList[i])
    }

    timeAv /= Double(algNum)
    print("\nAverage Algorithm Time: ", timeAv)
    //print(listBuff)
}

func quicksort(inout alist: [Int], first: Int, last: Int) {
    if first < last {
        let splitpoint = partion(&alist, first: first, last: last)
        quicksort(&alist, first: first, last: splitpoint - 1)
        quicksort(&alist, first: splitpoint + 1, last: last)
    }
}

func partion(inout alist: [Int], first: Int, last: Int) -> Int {
    let pivotValue = alist[last]
    var leftmark = first - 1

    for rightmark in first..<last {
        if alist[rightmark] < pivotValue {
            leftmark += 1
            swap(&alist, a: rightmark, b: leftmark)
        }
    }
    swap(&alist, a: leftmark+1, b: last)
    return leftmark+1
}

func swap(inout alist: [Int], a: Int, b: Int) {
    let temp = alist[a]
    alist[a] = alist[b]
    alist[b] = temp
}

func arrayFromContentsOfFileWithName(fileName: String) -> [String] {
    guard let path = NSBundle.mainBundle().pathForResource(fileName, ofType: "txt") else {
        print("ERROR: Couldn't open file")
        exit(0)
    }

    do {
        let content = try String(contentsOfFile:path, encoding: NSUTF8StringEncoding)
        return content.componentsSeparatedByString("\n")
    } catch _ as NSError {
        print("ERROR: Couldn't open file")
        exit(0)
    }
}

if Process.arguments.count != 2 {
    print("ERROR: Include a filename")
    exit(0)
}

let StringList = arrayFromContentsOfFileWithName(Process.arguments[1])
var alist = StringList.map { Int($0)!}
quicksortHelper(&alist, algNum: ALGLOOPNUM)


