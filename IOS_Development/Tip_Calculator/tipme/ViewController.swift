//
//  ViewController.swift
//  tipme
//
//  Created by Tyrone K. Harmon on 11/26/18.
//  Copyright © 2018 Tyrone K. Harmon. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var userdata: UITextField!
    @IBOutlet weak var mytotal: UILabel!
    @IBOutlet weak var mytip: UILabel!
    @IBOutlet weak var tipcontroler: UISegmentedControl!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    @IBAction func whentap(_ sender: AnyObject) {
        view.endEditing(true)
    }
    
    @IBAction func changelabels(_ sender: AnyObject) {
        let tipPercentages = [0.18,0.2,0.25]
        let bill = Double(userdata.text!) ?? 0
        let tip = bill * tipPercentages[tipcontroler.selectedSegmentIndex]
        let total = bill + tip
        
        mytip.text = String(format: "$%.2f", tip)
        mytotal.text = String(format: "$%.2f", total)
    }
}

