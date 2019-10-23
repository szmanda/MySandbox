package com.example.stopwatch

import android.os.Bundle
import android.os.Handler
import android.os.SystemClock
import android.support.v7.app.AppCompatActivity
import android.widget.ArrayAdapter
import android.widget.ImageButton
import android.widget.ListView
import android.widget.TextView


class MainActivity : AppCompatActivity() {


    var handler: Handler? = null
    var hour: TextView? = null
    var minute: TextView? = null
    var seconds: TextView? = null
    var milli_seconds: TextView? = null

    internal var MillisecondTime: Long = 0
    internal var StartTime: Long = 0
    internal var TimeBuff: Long = 0
    internal var UpdateTime = 0L


    internal var Seconds: Int = 0
    internal var Minutes: Int = 0
    internal var MilliSeconds: Int = 0

    internal var flag:Boolean=false

    var startButton: ImageButton? = null
    var listView: ListView? = null

    public var listaKategorii: Array<Category> = arrayOf(Category("Domyślna"))

    var currentCateory = 1


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        startButton = findViewById(R.id.startButton)
        bindViews()

        /////////////
        println("On create method started")

        var lv = findViewById<ListView>(R.id.list_view)

        var listaTytulow = arrayOfNulls<String>(listaKategorii.size)


        for (i in 0 until listaKategorii.size){
            val elementListy = listaKategorii[i]
            listaTytulow[i] = elementListy.toString()
        }

        val adapt = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, listaTytulow)
        lv.adapter = adapt

    }

    fun save(){
        val h = hour?.text.toString().toInt()
        val m = minute?.text.toString().toInt()
        val s = minute?.text.toString().toInt()

        val update = (h * 3600) + (m * 60) + s
        println("updating time with: " + update + " seconds")
        var doTeraz = listaKategorii[currentCateory].czas
        doTeraz = update + doTeraz.toString().toInt()

        listaKategorii[currentCateory].czas = doTeraz

    }

    override fun onPause() {
        println("application paused")
        save()

        super.onPause()
    }

    fun addCategory(name: String){
        listaKategorii.plus(Category(name))
    }



    // code below is borrowed :) i would not be able to write it,
    // at least not jet

    private fun bindViews() {

        hour = findViewById(R.id.hour)
        minute = findViewById(R.id.minute)
        seconds = findViewById(R.id.seconds)
        milli_seconds = findViewById(R.id.milli_second)


        startButton?.setOnClickListener {
            if (flag){
                handler?.removeCallbacks(runnable)
                startButton?.setImageResource(R.drawable.play)
                flag=false
            }else{
                startButton?.setImageResource(R.drawable.pause)
                StartTime = SystemClock.uptimeMillis()
                handler?.postDelayed(runnable, 0)
                flag=true
            }

        }

        handler = Handler()

    }
    var runnable: Runnable = object : Runnable {

        override fun run() {

            MillisecondTime = SystemClock.uptimeMillis() - StartTime

            UpdateTime = TimeBuff + MillisecondTime

            Seconds = (UpdateTime / 1000).toInt()

            Minutes = Seconds / 60

            Seconds = Seconds % 60

            MilliSeconds = (UpdateTime % 1000).toInt()


            if (Minutes.toString().length < 2) {
                minute?.text = "0" + Minutes.toString()
            } else {
                minute?.text = Minutes.toString()
            }
            if (Seconds.toString().length < 2) {
                seconds?.text = "0" + Seconds.toString()
            } else {
                seconds?.text = Seconds.toString()
            }

            milli_seconds?.text = MilliSeconds.toString()

            handler?.postDelayed(this, 0)
        }
    }
}

