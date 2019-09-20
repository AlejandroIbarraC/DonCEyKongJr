package com.donkeykongjr.entity;

public class Fruit {

    private Integer iD;
    public Integer iPos,jPos;
    public Integer onScreen, onField, onVine;
    public Integer whichFruit;

    public Fruit(){
        this.iD = 2;
    }

    public Integer getiD(){
        return this.iD;
    }
}
